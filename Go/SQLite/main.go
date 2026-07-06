// https://softchris.github.io/golang-book/05-misc/05-sqlite/
// https://github.com/practicalgo/go-sqlite-demo/tree/main
// https://pkg.go.dev/modernc.org/sqlite

package main

import (
	"database/sql"
	"fmt"
	"log"

	_ "modernc.org/sqlite"
)

// Create new table if it not exists
func Create(db *sql.DB) {
	_, err := db.Exec(
		`CREATE TABLE IF NOT EXISTS person (
         	uid INTEGER PRIMARY KEY AUTOINCREMENT,
         	username VARCHAR(64) NULL,
         	password VARCHAR(64) NULL
     	)`,
	)
	if err != nil {
		log.Fatal("Create function says: ", err)
	}
}

// Read the content of the database
func Read(db *sql.DB) {
	rows, err := db.Query("SELECT * FROM person")
	if err != nil {
		log.Fatal(err)
	}
	for rows.Next() {
		var uid int
		var username, password string
		if rows.Scan(&uid, &username, &password) != nil {
			log.Fatal(err)
		}
		fmt.Println(uid, username, password)
	}
}

// Add content to the table
func Add(db *sql.DB) {
	stmt, err := db.Prepare("INSERT INTO person(username, password) values(?,?)")
	if err != nil {
		log.Fatal(err)
	}
	_, err = stmt.Exec("papahana", "1234")
	if err != nil {
		log.Fatal(err)
	}
}

// Update the password for specific id
func Update(db *sql.DB) {
	stmt, err := db.Prepare("UPDATE person set password=? where uid=?")
	if err != nil {
		log.Fatal(err)
	}
	_, err = stmt.Exec("5678", 1)
	if err != nil {
		log.Fatal(err)
	}
}

func Delete(db *sql.DB) {
	stmt, err := db.Prepare("delete from person where uid=?")
	if err != nil {
		log.Fatal(err)
	}
	_, err = stmt.Exec(1)
	if err != nil {
		log.Fatal(err)
	}
}

func main() {
	db, err := sql.Open("sqlite", "./database/database.db")
	if err != nil {
		log.Fatal(err)
	}

	Create(db)
	Add(db)
	Read(db)
	// Update(db)
	// Delete(db)

	log.Println("Closing db ...")
	db.Close()
}
