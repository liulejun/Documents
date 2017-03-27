***PETRONE / LINK / Protocol / Structs***<br>
Modified : 2017.03.27

---

#### 송신 데이터 예제를 보여드립니다.

---

<br>

## <a name="LinkModeBroadcast_Active">LinkModeBroadcast - Active</a>
LINK를 Active 모드로 변경할 때 사용하는 명령입니다. PC 또는 아두이노 보드에서 LINK 모듈과 통신을 할 때 가장 먼저 이 명령을 전송하면 LINK 모듈의 버튼을 두 번 누르지 않고도 페트론 연결 모드로 전환됩니다. Active 모드일 때 아두이노 펌웨어를 업데이트하면 Mute모드로 자동 전환되므로 모드 전환은 이 명령만 사용하시면 됩니다.
<table>
    <tr>
        <td>0</td>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
        <td>5</td>
        <td>6</td>
        <td>7</td>
        <td>8</td>
    </tr>
    <tr>
        <td rowspan="2" colspan="2">Start code</td>
        <td colspan="2">Header</td>
        <td rowspan="2" colspan="2">Data</td>
        <td rowspan="2" colspan="2">CRC16</td>
    </tr>
    <tr>
        <td>DataType</td>
        <td>Length</td>
    </tr>
    <tr>
        <td>0A</td>
        <td>55</td>
        <td>11</td>
        <td>02</td>
        <td>E0</td>
        <td>02</td>
        <td>83</td>
        <td>33</td>
    </tr>
</table>

<br>
<br>
<br>

---
[Home](../../README.md)
