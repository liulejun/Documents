***PETRONE / LINK / Protocol / Intro***<br>
Modified : 2017.03.27

---

<br>

# 1. PETRONE LINK 소개
**PETRONE LINK**(이하 LINK)는 PETRONE과의 연결 및 제어를 도와주는 통신 모듈입니다. PETRONE과 LINK 사이에는 Bluetooth Low Energy(이하 BLE)를 사용하여 통신하지만, LINK 사용자는 BLE에 대해 신경 쓸 필요 없이 시리얼 통신만으로 PETRONE 과 연결 및 제어를 할 수 있습니다.


<br>
<br>

# 2. 전송 데이터 구조
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>2</td>
        <td>...</td>
        <td>N-1</td>
        <td>N</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0x0A</td>
        <td>0x55</td>
        <td>-</td>
        <td>-</td>
        <td>-</td>
        <td>-</td>
        <td>-</td>
    </tr>
</table>

<br>


<table>
    <tr>
        <td>영역</td>
        <td>설명</td>
    <tr>
    <tr>
        <td>Start code</td>
        <td>데이터 전송 시작을 알림</td>
    <tr>
    <tr>
        <td>Header</td>
        <td>헤더 뒤에 이어지는 데이터의 형식과 길이</td>
    <tr>
    <tr>
        <td>Data</td>
        <td>전송할 데이터</td>
    <tr>
    <tr>
        <td>CRC16</td>
        <td>Header와 Data가 정상적으로 전달되었는지 판별<br>http://www.menie.org/georges/embedded/crc16.html</td>
    <tr>
</table>

<br>
<br>

# 3. 데이터 송수신 규칙

- 데이터를 전송하는 주기는 **Android**인 경우 *50ms*, **iOS**인 경우 *100ms*를 권장
- PETRONE에 데이터를 요청한 경우엔 요청한 데이터를 응답으로 보냄. 이외의 경우에는 Ack를 응답. Control 명령은 Ack 및 어떤 응답도 보내지 않음
- 앱에서 드론에 명령 시에는 *DRONE_CONF*에 전달할 데이터를 **Write**
- 드론이 앱으로 데이터를 보내는 경우엔 *DRONE_DATA*로 **Notify**를 전송


<br>

---
[Home](../../README.md)
