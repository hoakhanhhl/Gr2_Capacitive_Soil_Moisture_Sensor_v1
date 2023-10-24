# Gr2_Capacitive_Soil_Moisture_Sensor_v1

## HƯỚNG DẪN LẮP MẠCH:
Để nối cảm biến độ ẩm đất điện dung (Capacitive Soil Moisture Sensor v1) với DOIT esp32 devkit v1, nối các chân tương ứng:
+ Chân VCC của cảm biến nối với nguồn điện 3.3V trên ESP32 (chọn nguồn phù hợp với yêu cầu của cảm biến).
+ Chân GND của cảm biến nối với chân GND trên ESP32 để tạo đường dẫn chung cho điện áp.
+ Chân AOUT (hoặc SIG) của cảm biến nối với một chân ADC trên ESP32 để đọc giá trị analog. Bạn có thể chọn bất kỳ chân ADC nào trên ESP32, ví dụ: chân D34 thì trong code cần để (const int soilMoisturePin = 34;).

## Link ảnh kết quả chạy và hướng dẫn lắp mạch: 
https://drive.google.com/drive/folders/1um0Sst3s8K079WxdG2W0pAMI-CHuCW1n

## Thông số của Capacitive Soil Moisture Sensor v1:
+ Sơ đồ chân: 
VCC: 3.3V ~ 5V
GND: GND của nguồn ngoài
DO: Đầu ra tín hiệu số (mức cao hoặc mức thấp)
AO: Đầu ra tín hiệu tương tự (Analog)
+ Điện áp hoạt động: 3.3~5VDC
+ Tín hiệu đầu ra:
Analog: theo điện áp cấp nguồn tương ứng.
Digital: High hoặc Low, có thể điều chỉnh độ ẩm mong muốn bằng biến trở thông qua mạch so sánh LM393 tích hợp.


##Hướng dẫn chạy:
+ Đặt board (trong tool -> board): DOIT ESP32 DEVKIT V1 (tải esp32 by Espressif Systems)
+ Đặt port phù hợp với cổng usb đã cắm
+ Kết quả được hiển thị ở Serial Monitor. Để tốc độ là 115200 baud
+ Dải giá trị của biến soilMoistureValue (giá trị đọc được từ cảm biến độ ẩm đất) phụ thuộc vào cảm biến cụ thể và cách hiệu chỉnh của nó. Thông thường, giá trị đọc từ chân ADC sẽ nằm trong khoảng từ 0 đến 4095 trên ESP32, với 0 đại diện cho mức thấp nhất và 4095 đại diện cho mức cao nhất.

##Nguyên lí hoạt động:
+ Cảm biến độ ẩm đất điện dung (Capacitive Soil Moisture Sensor) hoạt động dựa trên nguyên lý thay đổi điện dung của đất khi độ ẩm thay đổi. Khi đất khô, nó có khả năng cách điện tốt hơn, dẫn đến giá trị điện dung thấp. Khi đất ẩm, nước trong đất làm tăng khả năng dẫn điện và giá trị điện dung cao hơn. Cảm biến sẽ đo giá trị điện dung giữa các điện cực và chuyển đổi nó thành một tín hiệu điện analog hoặc số để đo lường độ ẩm của đất. Kết nối với  DOIT ESP32 DevKit V1 và sử dụng chức năng ADC để đọc giá trị analog từ cảm biến.
 
##Giải thích code: 
const int soilMoisturePin = 34;  // Khai báo biến soilMoisturePin và gán giá trị là số 34, chân ADC trên ESP32 (chân D34) đã sử dụng để kết nối với Capacitive Soil Moisture Sensor.
int soilMoistureValue = 0; // Khai báo biến soilMoistureValue và gán giá trị ban đầu là 0, biến này sẽ lưu trữ giá trị đọc từ cảm biến.

void setup() {
  Serial.begin(115200);  // Khởi tạo kết nối với Serial Monitor với tốc độ baud 115200 để hiển thị thông tin đọc từ cảm biến.
}

void loop() {
  soilMoistureValue = analogRead(soilMoisturePin);  //Đọc giá trị từ chân ADC (D34) bằng cách sử dụng hàm analogRead() và lưu giá trị vào biến soilMoistureValue.
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);  // In chuỗi "Soil Moisture: " và giá trị đọc được từ cảm biến ra Serial Monitor.

  delay(1000);  // Chờ 1 giây trước khi đọc giá trị tiếp theo
}


