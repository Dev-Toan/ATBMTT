# ATBMTT

> Bộ sưu tập các thuật toán mật mã được cài đặt bằng C++ phục vụ học tập và minh họa.

Repo này bao gồm các thuật toán mã hóa cổ điển và hiện đại như **RSA**, **ElGamal**, **Caesar Cipher**, **Affine Cipher**.

---

## 📂 Cấu trúc thư mục

```
ATBMTT/
├── RSA.cpp        # Thuật toán RSA
├── elgamal.cpp    # Thuật toán ElGamal
├── caser.cpp      # Thuật toán Caesar
├── afine.cpp      # Thuật toán Affine
└── README.md      # Tài liệu dự án
```

---

## 🚀 Các thuật toán trong dự án

* **RSA**: Thuật toán mã hóa khóa công khai dựa trên số nguyên tố lớn.
* **ElGamal**: Thuật toán mã hóa bất đối xứng dựa vào logarit rời rạc.
* **Caesar cipher**: Thuật toán mã hóa thay thế đơn giản bằng cách dịch chuyển ký tự.
* **Affine cipher**: Kết hợp phép nhân và cộng để mã hoá, mở rộng từ Caesar.

---

## ⚙️ Yêu cầu môi trường

* Trình biên dịch C++ hỗ trợ **C++11** hoặc mới hơn (g++/clang++/MSVC).
* Hệ điều hành: Windows / Linux / macOS.
* Có thể dùng IDE (Visual Studio, Code::Blocks, CLion) hoặc terminal (nên dùng terminal để có thể hiển thị tiếng việt mà không cần cài thêm thư viện bên ngoài).

---

## 🔨 Cách biên dịch và chạy

Biên dịch từng file riêng lẻ:

sử dụng trực tiếp trên terminal
```bash
g++ -o rsa rsa.cpp
g++ -o elgamal elgamal.cpp 
g++ -o caesar caser.cpp 
g++ -o affine afine.cpp 

---

## 📝 Ví dụ sử dụng

**Caesar Cipher:**

```
Nhập văn bản: HELLO
Nhập độ dịch chuyển: 3
Bản mã: KHOOR
```

**Affine Cipher (a=5, b=8):**

```
Nhập văn bản: TEST
Bản mã: ZEBW
```

---

## 🤝 Đóng góp

Mọi ý tưởng và đóng góp đều được hoan nghênh:
---

## 📜 Giấy phép
```
MIT License

Copyright (c) 2025 Dev-Toan
---

## 📧 Liên hệ

* GitHub: [Dev-Toan](https://github.com/Dev-Toan)
* Repo: [ATBMTT](https://github.com/Dev-Toan/ATBMTT)

---

✨ Cảm ơn bạn đã ghé thăm repo! Hy vọng dự án giúp ích cho việc học tập và nghiên cứu của bạn.
