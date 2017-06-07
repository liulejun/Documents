//
//  CommonProtocol.h
//  FPVPlugin
//
//  Created by byrobot on 2016. 7. 12..
//  Copyright © 2016년 이각규. All rights reserved.
//

#ifndef CommonProtocol_h
#define CommonProtocol_h

namespace ByrobotProtocol {
    namespace DataType
    {
        enum Enum
        {
            None = 0,                   ///< 없음
            
            // 시스템 정보
            Ping,                       ///< 통신 확인(reserve)
            Ack,                        ///< 데이터 수신에 대한 응답
            Error,                      ///< 오류(reserve, 비트 플래그는 추후에 지정)
            Request,                    ///< 지정한 타입의 데이터 요청
            Passcode,                   ///< 새로운 페어링 비밀 번호
            
            // 조종, 명령
            Control = 0x10,             ///< 조종
            Command,                    ///< 명령
            Command2,                   ///< 다중 명령(2가지 설정을 동시에 변경)
            Command3,                   ///< 다중 명령(3가지 설정을 동시에 변경)
            
            // LED
            LedMode = 0x20,             ///< LED 모드 지정
            LedMode2,                   ///< LED 모드 2개 지정
            LedModeCommand,             ///< LED 모드, 커맨드
            LedModeCommandIr,           ///< LED 모드, 커맨드, IR 데이터 송신
            LedModeColor,               ///< LED 모드 3색 직접 지정
            LedModeColor2,              ///< LED 모드 3색 직접 지정 2개
            
            LedEvent,                   ///< LED 이벤트
            LedEvent2,                  ///< LED 이벤트 2개,
            LedEventCommand,            ///< LED 이벤트, 커맨드
            LedEventCommandIr,          ///< LED 이벤트, 커맨드, IR 데이터 송신
            LedEventColor,              ///< LED 이벤트 3색 직접 지정
            LedEventColor2,             ///< LED 이벤트 3색 직접 지정 2개
            
            LedModeDefaultColor,            ///< LED 초기 모드 3색 직접 지정
            LedModeDefaultColor2,           ///< LED 초기 모드 3색 직접 지정 2개
            
            // 상태
            Address = 0x30,             ///< IEEE address
            State,                      ///< 드론의 상태(비행 모드, 방위기준, 배터리량)
            Attitude,                   ///< 드론의 자세(Vector)
            GyroBias,                   ///< 자이로 바이어스 값(Vector)
            TrimAll,                    ///< 전체 트림
            TrimFlight,                 ///< 비행 트림
            TrimDrive,                  ///< 주행 트림
            
            CountFlight,                ///< 비행 관련 카운트
            CountDrive,                 ///< 주행 관련 카운트
            
            
            // 데이터 송수신
            IrMessage = 0x40,           ///< IR 데이터 송수신
            
            
            // 센서 및 제어
            ImuRawAndAngle = 0x50,      ///< IMU Raw + Angle
            Pressure,                   // 압력 센서 데이터
            ImageFlow,                  // ImageFlow
            Button,                     // 버튼 입력
            Battery,                    // 배터리
            Motor,                      // 모터 제어 및 현재 제어값 확인
            Temperature,                // 온도 데이터
            Range,                      // 거리 센서
            
            // 펌웨어 업데이트
            UpdateLookupTarget = 0x90,  ///< 업데이트 대상 장치 검색
            UpdateInformation,          ///< 업데이트 정보
            Update,                     ///< 업데이트(16바이트 단위)
            UpdateLocationCorrect,      ///< 업데이트 위치 정정
            
            EndOfType
        };
    };
    
    namespace CommandType
    {
        enum Enum
        {
            None = 0,                   ///< 이벤트 없음
            
            // 설정
            ModePetrone = 0x10,         ///< 페트론 동작 모드 전환
            
            // 제어
            Coordinate = 0x20,          ///< 방위 기준 변경
            Trim,                       ///< 트림 변경
            FlightEvent,                ///< 비행 이벤트 실행
            DriveEvent,                 ///< 주행 이벤트 실행
            Stop,                       ///< 정지
            
            ResetHeading = 0x50,        ///< 방향을 리셋(앱솔루트 모드 일 때 현재 heading을 0도로 변경)
            ClearGyroBiasAndTrim,       ///< 자이로 바이어스와 트림 설정 초기화
            
            // 통신[Wireless Lan]
            ResetWirelessLanSetup = 0x70,    ///< 무선랜 설정 리셋
            WirelessLanConnected,       ///< 무선랜 연결
            WirelessLanDisconnected,    ///< 무선랜 연결 해제
            
            // 통신
            PairingActivate = 0x80,     ///< 페어링 활성화
            PairingDeactivate,          ///< 페어링 비활성화
            AdvertisingStart,           ///< 장치를 검색 가능한 상태로 변경
            AdvertisingStop,            ///< 장치를 검색 불가능한 상태로 변경
            TerminateConnection,        ///< 연결 종료
            ClearBondList,              ///< 본딩된 장치 리스트 제거
            
            // 요청
            Request = 0x90,             ///< 지정한 타입의 데이터 요청
            UpdateComplete,             ///< 업데이트 완료 처리
            ClearUpdateArea,            ///< 업데이트 할 영역 지우기(Main)
            
            // 관리자
            ClearCounter = 0xA0,        ///< 카운터 클리어(관리자 권한을 획득했을 경우에만 동작)
            
            // PETRONE 내부 장치 상호 제어
            SystemEvent = 0xB0,         ///< 시스템 이벤트
            
            // 테스터
            Tester = 0xD0,
            
            // PETRONE LINK
            LinkModeBroadcast = 0xE0,	///< LINK 송수신 모드 전환
            LinkSystemReset,			///< 시스템 재시작
            LinkDiscoverStart,			///< 장치 검색 시작
            LinkDiscoverStop,			///< 장치 검색 중단
            LinkConnect,				///< 연결
            LinkDisconnect,				///< 연결 해제
            LinkRssiPollingStart,		///< RSSI 수집 시작
            LinkRssiPollingStop,		///< RSSI 수집 중단
            
            EndOfType
        };
    };
    
    namespace ModeUpdate
    {
        enum Enum
        {
            None,       // 업데이트 불가능 상태(Debug 모드 등)
            
            Ready,      // 업데이트 가능 상태
            Update,     // 업데이트 중
            Complete,   // 업데이트 완료
            
            Faild,      // 업데이트 실패(업데이트 완료까지 갔으나 body의 CRC16이 일치하지 않는 경우)
            
            EndOfModeUpdate
        };
    };
    
    namespace FlightEvent
    {
        enum Enum
        {
            None = 0,           ///< 없음
            
            TakeOff,            ///< 이륙
            
            FlipFront,          ///< 회전
            FlipRear,           ///< 회전
            FlipLeft,           ///< 회전
            FlipRight,          ///< 회전
            
            Stop,               ///< 정지
            Landing,            ///< 착륙
            TurnOver,           ///< 뒤집기
            
            Shot,               ///< 미사일 쏠때 움직임
            UnderAttack,        ///< 미사일 맞을때 움직임
            Square,             ///< 정방향 돌기
            CircleLeft,
            CircleRight,
            Rotate180,
            
            EndOfType
        };
    };
    namespace DriveEvent
    {
        enum Enum
        {
            None = 0,           ///< 없음
            
            Stop,               ///< 정지
            
            Shot,               ///< 미사일 쏠때 움직임
            UnderAttack,        ///< 미사일 맞을때 움직임
            Square,             ///< 정방향 돌기
            CircleLeft,
            CircleRight,
            Rotate90Left,
            Rotate90Right,
            Rotate180,
            Rotate3600,
            
            EndOfType
        };
    };
    
    namespace Light
    {
        namespace Mode
        {
            enum Enum
            {
                None,
                
                WaitingForConnect,      ///< 연결 대기 상태
                Connected,
                
                EyeNone = 0x10,
                EyeHold,                ///< 지정한 색상을 계속 켬
                EyeMix,                 ///< 순차적으로 LED 색 변경
                EyeFlicker,             ///< 깜빡임
                EyeFlickerDouble,       ///< 깜빡임(두 번 깜빡이고 깜빡인 시간만큼 꺼짐)
                EyeDimming,             ///< 밝기 제어하여 천천히 깜빡임
                
                ArmNone = 0x40,
                ArmHold,                ///< 지정한 색상을 계속 켬
                ArmMix,                 ///< 순차적으로 LED 색 변경
                ArmFlicker,             ///< 깜빡임
                ArmFlickerDouble,       ///< 깜빡임(두 번 깜빡이고 깜빡인 시간만큼 꺼짐)
                ArmDimming,             ///< 밝기 제어하여 천천히 깜빡임
                ArmFlow,                ///< 앞에서 뒤로 흐름
                ArmFlowReverse,         ///< 뒤에서 앞으로 흐름
                
                EndOfType
            };
        };
        
        namespace Colors
        {
            enum Enum
            {
                AliceBlue,
                AntiqueWhite,
                Aqua,
                Aquamarine,
                Azure,
                Beige,
                Bisque,
                Black,
                BlanchedAlmond,
                Blue,
                BlueViolet,
                Brown,
                BurlyWood,
                CadetBlue,
                Chartreuse,
                Chocolate,
                Coral,
                CornflowerBlue,
                Cornsilk,
                Crimson,
                Cyan,
                DarkBlue,
                DarkCyan,
                DarkGoldenRod,
                DarkGray,
                DarkGreen,
                DarkKhaki,
                DarkMagenta,
                DarkOliveGreen,
                DarkOrange,
                DarkOrchid,
                DarkRed,
                DarkSalmon,
                DarkSeaGreen,
                DarkSlateBlue,
                DarkSlateGray,
                DarkTurquoise,
                DarkViolet,
                DeepPink,
                DeepSkyBlue,
                DimGray,
                DodgerBlue,
                FireBrick,
                FloralWhite,
                ForestGreen,
                Fuchsia,
                Gainsboro,
                GhostWhite,
                Gold,
                GoldenRod,
                Gray,
                Green,
                GreenYellow,
                HoneyDew,
                HotPink,
                IndianRed,
                Indigo,
                Ivory,
                Khaki,
                Lavender,
                LavenderBlush,
                LawnGreen,
                LemonChiffon,
                LightBlue,
                LightCoral,
                LightCyan,
                LightGoldenRodYellow,
                LightGray,
                LightGreen,
                LightPink,
                LightSalmon,
                LightSeaGreen,
                LightSkyBlue,
                LightSlateGray,
                LightSteelBlue,
                LightYellow,
                Lime,
                LimeGreen,
                Linen,
                Magenta,
                Maroon,
                MediumAquaMarine,
                MediumBlue,
                MediumOrchid,
                MediumPurple,
                MediumSeaGreen,
                MediumSlateBlue,
                MediumSpringGreen,
                MediumTurquoise,
                MediumVioletRed,
                MidnightBlue,
                MintCream,
                MistyRose,
                Moccasin,
                NavajoWhite,
                Navy,
                OldLace,
                Olive,
                OliveDrab,
                Orange,
                OrangeRed,
                Orchid,
                PaleGoldenRod,
                PaleGreen,
                PaleTurquoise,
                PaleVioletRed,
                PapayaWhip,
                PeachPuff,
                Peru,
                Pink,
                Plum,
                PowderBlue,
                Purple,
                RebeccaPurple,
                Red,
                RosyBrown,
                RoyalBlue,
                SaddleBrown,
                Salmon,
                SandyBrown,
                SeaGreen,
                SeaShell,
                Sienna,
                Silver,
                SkyBlue,
                SlateBlue,
                SlateGray,
                Snow,
                SpringGreen,
                SteelBlue,
                Tan,
                Teal,
                Thistle,
                Tomato,
                Turquoise,
                Violet,
                Wheat,
                White,
                WhiteSmoke,
                Yellow,
                YellowGreen,
                
                EndOfColor
            };
        };
    };

    namespace ModePetrone {
        enum Enum
        {
            None = 0,           ///< 없음
            
            Flight = 0x10,      ///< 비행(가드 포함)
            FlightNoGuard,      ///< 비행(가드 없음)
            FlightFPV,          ///< 비행(FPV)
            
            Drive = 0x20,       ///< 주행
            DriveFPV,           ///< 주행(FPV)
            
            Test = 0x30,        ///< 테스트
            
            EndOfType
        };
    };
    
    namespace ModeVehicle {
        enum Enum
        {
            None = 0,			///< 없음
            
            Boot,				///< 부팅
            Wait,				///< 연결 대기 상태
            
            Ready,              ///< 대기 상태
            
            Running,            ///< 메인 코드 동작
            
            Update,				///< 펌웨어 업데이트
            UpdateComplete,		///< 펌웨어 업데이트 완료
            
            Error,				///< 오류
            
            EndOfType
        };
    };
    
    namespace ModeFlight {
        enum Enum
        {
            None = 0,           ///< 없음
            
            Ready,              ///< 비행 준비
            
            TakeOff,            ///< 이륙 (Flight로 자동전환)
            Flight,             ///< 비행
            Flip,               ///< 회전
            Stop,               ///< 강제 정지
            Landing,            ///< 착륙
            Reverse,            ///< 뒤집기
            
            Accident,           ///< 사고 (Ready로 자동전환)
            Error,              ///< 오류
            
            EndOfType
        };
    };
    
    namespace ModeDrive {
        enum Enum
        {
            None = 0,			///< 없음
            
            Ready,				///< 준비
            
            Start,				///< 출발
            Drive,				///< 주행
            Stop,				///< 강제 정지
            
            Accident,			///< 사고 (Ready로 자동전환)
            Error,				///< 오류
            
            EndOfType
        };
    };
    
    namespace Coordinate {
        enum Enum
        {
            None = 0,           ///< 없음
            
            Absolute,           ///< 고정 좌표계
            Relative,           ///< 상대 좌표계
            Fixed,              ///< 헤딩 고정	(Yaw 변경이 없을 경우 최초의 헤딩으로 돌아옴)
            
            EndOfType
        };
    };
    
    namespace Direction {
        enum Enum
        {
            None = 0,
            
            Left,
            Front,
            Right,
            Rear,
            
            EndOfType
        };
    };
    
    namespace SensorOrientation {
        enum Enum
        {
            None = 0,
            
            Normal,         // 정상
            ReverseStart,   // 뒤집히기 시작
            Reversed,       // 뒤집힘
            
            EndOfType
        };
    };
    
    
    /// Firmware
    namespace Firmware
    {
        enum ImageType
        {
            ImageType_None,
            
            // 현재 장치의 이미지
            ImageA,
            ImageB,
            
            // 펌웨어 이미지
            RawImageA,
            RawImageB,
            
            EncryptedImageA,
            EncryptedImageB,
            
            EndOfImageType
        };
        
        enum DeviceType
        {
            DeviceType_None,
            
            PetroneMain,        // STM32F4
            PetroneSub,         // CC2541
            PetroneLink,        // CC2541
            PetroneTester,      // STM32F4
            
            EndOfDeviceType
        };
        
        enum State
        {
            Ready,              // 대기 상태
            Updating,           // 업데이트 진행 중
            UpdateComplete      // 업데이트 완료
        };
        
        class Updater
        {
            class ImageHeader
            {
            public:
                DeviceType deviceType;
                ImageType imageType;
                uint16_t imageVersion;
            };
            
            
            const static int BLOCK_SIZE = 16;
            const static int HAL_FLASH_WORD_SIZE = 4;
            const static int BUFFER_SIZE = 2 + BLOCK_SIZE;      // BLE 데이터 최대 전송량은 20byte
        };
    };
};

#endif /* CommonProtocol_h */
