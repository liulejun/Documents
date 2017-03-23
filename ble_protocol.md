# PETRONE

***BLE / Protocol***<br>
Modified : 2017.03.23

---


**1. PETRONE의 통신**
-----------------
**PETRONE**은 무선 연결에 Bluetooth Low Energy(이하 BLE)를 사용합니다.<br>
BLE는 장치 간 데이터 교환 시 Characteristic에 값을 쓰거나, 읽거나, 통지하는 방법을 사용합니다.<br>
**PETRONE**에서 사용하는 **Service**와 **Characteristic**은 다음과 같습니다.

| Service        | Characteristic | UUID                                   | 데이터 이동 방향      |
|:--------------:|:--------------:|:--------------------------------------:|:---------------------:|
| DRONE_SERVICE  |                | *C320DF00-7891-11E5-8BCF-FEFF819CDC9F* |                       |
|   ├           | DRONE_DATA     | *C320DF01-7891-11E5-8BCF-FEFF819CDC9F* | 드론 → 앱 (*Notify*) |
|   └           | DRONE_CONF     | *C320DF02-7891-11E5-8BCF-FEFF819CDC9F* | 앱 → 드론 (*Write*)  |



**2. 전송 데이터 구조**
-----------------
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>...</td>
        <td>N-1</td>
        <td>N</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td colspan="4">Data</td>
    </tr>
</table>

- 첫 번째 바이트는 데이터 타입을 의미
- 두 번째 바이트부터는 첫 번째 바이트(데이터의 타입)에서 정의한 데이터 전달
- 전체 길이는 최대 20byte



**3. 데이터 송수신 규칙**
-----------------

- 데이터를 전송하는 주기는 **Android**인 경우 *50ms*, **iOS**인 경우 *100ms*를 권장
- PETRONE에 데이터를 요청한 경우엔 요청한 데이터를 응답으로 보냄. 이외의 경우에는 Ack를 응답. Control 명령은 Ack 및 어떤 응답도 보내지 않음
- 앱에서 드론에 명령 시에는 *DRONE_CONF*에 전달할 데이터를 **Write**
- 드론이 앱으로 데이터를 보내는 경우엔 *DRONE_DATA*로 **Notify**를 전송



---
[Home](README.md)
