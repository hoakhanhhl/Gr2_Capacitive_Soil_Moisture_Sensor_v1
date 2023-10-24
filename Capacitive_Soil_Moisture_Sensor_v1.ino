const int soilMoisturePin = 34;  // Chân ADC trên ESP32 (chân D34)
int soilMoistureValue = 0;

void setup() {
  Serial.begin(115200);  // Khởi tạo kết nối với Serial Monitor với tốc độ baud 115200
}

void loop() {
  soilMoistureValue = analogRead(soilMoisturePin);  // Đọc giá trị từ chân ADC
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);  // In giá trị đọc được ra Serial Monitor

  delay(1000);  // Chờ 1 giây trước khi đọc giá trị tiếp theo
}
// const int soilMoisturePin = 34;: Khai báo biến soilMoisturePin và gán giá trị là số 34, đại diện cho chân ADC trên ESP32 (chân D34) mà bạn sử dụng để kết nối với Capacitive Soil Moisture Sensor.

// int soilMoistureValue = 0;: Khai báo biến soilMoistureValue và gán giá trị ban đầu là 0, biến này sẽ lưu trữ giá trị đọc từ cảm biến.

// Serial.begin(115200);: Khởi tạo kết nối với Serial Monitor với tốc độ baud 115200 để hiển thị thông tin đọc từ cảm biến.

// soilMoistureValue = analogRead(soilMoisturePin);: Đọc giá trị từ chân ADC (D34) bằng cách sử dụng hàm analogRead() và lưu giá trị vào biến soilMoistureValue.

// Serial.print("Soil Moisture: "); và Serial.println(soilMoistureValue);: In chuỗi "Soil Moisture: " và giá trị đọc được từ cảm biến ra Serial Monitor để hiển thị.

// delay(1000);: Chờ 1 giây trước khi đọc giá trị từ cảm biến lần tiếp theo.
// Serial Monitor: 115200 baud
// board: DOIT ESP32 DEVKIT V1