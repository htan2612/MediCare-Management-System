# CLINIC 2026 - PROGRESS UPDATE

## ĐÃ LÀM XONG (DONE)
- **Cấu trúc Folder:** Chia 3 file (`.h`, `.cpp`, `main.cpp`) đúng chuẩn Modular.
- **Giao diện (UI/UX):**
    - Menu điều khiển bằng phím mũi tên (không cần nhập số).
    - Logo ASCII & Khung đồ họa chuyên nghiệp.
    - Hiệu ứng Loading & Màu sắc phân loại (Xanh/Vàng/Đỏ).
- **Core cơ bản:** Khai báo Struct `Patient` và chức năng Nhập/Xem danh sách sơ khai.

## CÒN THIẾU (TO-DO)
1.  **Lưu/Đọc File:** Chưa có hàm ghi dữ liệu ra file `.bin` (G2.3).
2.  **Hàng đợi (Queue):** Chưa làm hệ thống gọi tên bệnh nhân theo thứ tự (G3.2).
3.  **Lịch sử khám (Linked List):** Mỗi bệnh nhân chưa có danh sách các lần khám cũ (G3.1).
4.  **Kho thuốc (Stack):** Chưa làm phần nhập/xuất thuốc LIFO (G3.2).
5.  **Thống kê (2D Array):** Chưa có bảng tổng hợp ca khám theo ngày/tháng (G1.4).
6.  **Tìm kiếm & Sắp xếp:** Chưa viết hàm tìm theo tên/ID (G2.1).
7.  **Xuất Report:** Chưa có hàm xuất ra file `.txt` (G2.3).

## CÁCH CHẠY CODE HIỆN TẠI (VS CODE):
Mở Terminal và gõ:
```bash
g++ *.cpp -o Clinic
./Clinic
```

---
**Ghi chú:** Phần giao diện đã xong. Giờ nhóm mình chỉ cần tập trung viết các hàm xử lý logic (Queue, Stack, Linked List) để đắp vào các Case trong `main.cpp` là hoàn thành.