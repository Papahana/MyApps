package main

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/md5"
	"crypto/rand"
	"encoding/hex"
	"fmt"
	"io"
	"os"
)

var println = fmt.Println

func createHash(key string) string {
	hasher := md5.New()
	hasher.Write(([]byte(key)))
	return hex.EncodeToString(hasher.Sum(nil))
}

func encrypt(data []byte, passphrase string) []byte {
	block, _ := aes.NewCipher(([]byte(createHash(passphrase))))
	gcm, _ := cipher.NewGCM(block)
	nonce := make([]byte, gcm.NonceSize())
	io.ReadFull(rand.Reader, nonce)
	ciphertext := gcm.Seal(nonce, nonce, data, nil)
	return ciphertext
}

func decrypt(data []byte, passphrase string) []byte {
	key := []byte(createHash(passphrase))
	block, _ := aes.NewCipher(key)
	gcm, _ := cipher.NewGCM(block)
	nonceSize := gcm.NonceSize()
	nonce, ciphertext := data[:nonceSize], data[nonceSize:]
	plaintext, _ := gcm.Open(nil, nonce, ciphertext, nil)
	return plaintext
}

func main() {
	ciphertext := encrypt([]byte("Hello World"), "password")
	f, _ := os.Create("ciphertext.txt")

	f.Write(ciphertext)
	content, _ := os.ReadFile("ciphertext.txt")

	plaintext := string(decrypt(content, "password"))
	println(plaintext)
}
