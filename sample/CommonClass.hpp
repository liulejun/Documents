//
//  CommonClass.hpp
//  FPVPlugin
//
//  Created by byrobot on 2016. 7. 11..
//  Copyright © 2016년 이각규. All rights reserved.
//

#ifndef CommonClass_hpp
#define CommonClass_hpp

#include <stdio.h>
#include <stdint.h>
#include "CommonProtocol.h"

namespace ByrobotProtocol {
    class CRC16
    {
    public:
        static uint16_t getCRC(const uint8_t* dataArray, int dataLength);
        static uint16_t getCRC(const uint8_t* header, int headerLength, const uint8_t* dataArray, int dataLength);
    };
    
    class CSerializer
    {
    public:
        CSerializer();
        int GetCounter();
        bool Add(uint8_t* target, bool value);
        bool Add(uint8_t* target, uint8_t value);
        bool Add(uint8_t* target, int8_t value);
        bool Add(uint8_t* target, int16_t value);
        bool Add(uint8_t* target, uint16_t value);
        bool Add(uint8_t* target, int32_t value);
        bool Add(uint8_t* target, uint32_t value);
        bool Add(uint8_t* target, int64_t value);
        bool Add(uint8_t* target, uint64_t value);
        bool Add(uint8_t* target, const uint8_t* value, int length);
    private:
        int m_counter;
    };
    
    class CExtractor
    {
    public:
        CExtractor(uint8_t* data);
        int GetCounter();
        
        bool            GetBool();
        char            GetChar();
        short           GetShort();
        unsigned short  GetUShort();
        int             GetInt();
        unsigned int    GetUInt();
        long long       GetInt64();
        unsigned long long GetUInt64();
    private:
        int m_counter;
        uint8_t* m_dataArray;
    };
    
    class CCommandBase
    {
    public:
        CCommandBase();
        
        int GetSize();
        static CCommandBase* Parse(uint8_t* dataArray);
        const uint8_t* ToArray();
        
        CommandType::Enum commandType;
        uint8_t option;
    private:
        int m_size;
    };
    
    class CRequest
    {
    public:
        CRequest();
        
        static const CRequest* Parse(uint8_t* dataArray);
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        DataType::Enum dataType;		///< 수신 받은 타입
        
    private:
        int m_size;
    };
    
    
    class CControl
    {
    public:
        CControl();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        DataType::Enum dataType;		///< 수신 받은 타입
        int8_t roll;
        int8_t pitch;
        int8_t yaw;
        int8_t throttle;
    private:
        int m_size;
    };
    
    
    class CCommand
    {
    public:
        CCommand();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        CCommandBase *command;
    private:
        int m_size;
    };
    
    
    class CCommand2
    {
    public:
        CCommand2();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        CCommandBase *command1;
        CCommandBase *command2;
    private:
        int m_size;
    };
    
    class CUpdateLookupTarget
    {
    public:
        CUpdateLookupTarget();
        
        static CUpdateLookupTarget* Parse(uint8_t* dataArray);
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        Firmware::DeviceType deviceType;
    private:
        int m_size;
    };
    
    class CUpdateInformation
    {
    public:
        CUpdateInformation();
        
        static CUpdateInformation* Parse(uint8_t* dataArray);        
    
        ModeUpdate::Enum modeUpdate;		///< 수신 받은 타입
        Firmware::DeviceType deviceType;
        Firmware::ImageType imageType;
        uint16_t    imageVersion;
        
        uint8_t     year;
        uint8_t     month;
        uint8_t     day;
    private:
        int m_size;
    };


    class CUpdate
    {
    public:
        CUpdate();

        uint16_t indexBlock;
        uint8_t* dataBlock;

        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
    private:
        int m_size;
    };

    class CLedModeBase
    {
    public:
        CLedModeBase();
        int GetSize();
        static CLedModeBase* Parse(uint8_t* dataArray);
        const uint8_t* ToArray();
        
        Light::Mode::Enum mode;
        Light::Colors::Enum colors;
        uint8_t interval;
    private:
        int m_size;
    };
    
    class CLedMode
    {
    public:
        CLedMode();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        CLedModeBase *ledMode;
    private:
        int m_size;
    };
    
    class CLedMode2
    {
    public:
        CLedMode2();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        CLedModeBase *ledMode1;
        CLedModeBase *ledMode2;
    private:
        int m_size;
    };
    
    class CLedEventBase
    {
    public:
        CLedEventBase();
        
        static CLedEventBase* Parse(uint8_t* dataArray);
        const uint8_t* ToArray();
        int GetSize();
        
        Light::Mode::Enum mode;
        Light::Colors::Enum colors;
        uint8_t interval;
        uint8_t repeat;
    private:
        int m_size;
    };
    
    class CLedModeColorBase
    {
    public:
        CLedModeColorBase();
        
        static CLedModeColorBase* Parse(uint8_t* dataArray);
        const uint8_t* ToArray();
        int GetSize();
        
        Light::Mode::Enum mode;
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t interval;
    private:
        int m_size;
    };
    
    class CLedModeColor
    {
    public:
        CLedModeColor();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        CLedModeColorBase *ledModeColorBase;
    private:
        int m_size;
    };
    
    class CLedModeColor2
    {
    public:
        CLedModeColor2();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        CLedModeColorBase *ledModeColorBase1;
        CLedModeColorBase *ledModeColorBase2;
    private:
        int m_size;
    };
    
    class CLedEventCommand
    {
    public:
        CLedEventCommand();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        CCommandBase *ledCommand;
        CLedEventBase *ledEvent;
    private:
        int m_size;
    };
    
    class CLedEventCommandIr
    {
    public:
        CLedEventCommandIr();
        
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        int GetSize();
        
        CCommandBase *ledCommand;
        CLedEventBase *ledEvent;
        uint32_t        irData;
    private:
        int m_size;
    };
    
    class CState
    {
    public:
        CState();
        int GetSize();
        static CState* Parse(uint8_t* dataArray);
        
        ModePetrone::Enum       modePetrone;
        
        ModeVehicle::Enum       modeVehicle;
        ModeFlight::Enum        modeFlight;
        ModeDrive::Enum         modeDrive;
        
        SensorOrientation::Enum sensorOrientation;
        Coordinate::Enum        coordinate;
        char battery;
        
        CState& operator << ( const CState& arg )
        {
            if( this !=  & arg )
            {
                modePetrone = arg.modePetrone;
                modeVehicle = arg.modeVehicle;
                modeFlight = arg.modeFlight;
                modeDrive = arg.modeDrive;
                sensorOrientation = arg.sensorOrientation;
                coordinate = arg.coordinate;
                battery = arg.battery;
            }
            return *this;
        }
    private:
        int m_size;
    };
    
    class CTrimFlightBase
    {
    public:
        CTrimFlightBase();
        int16_t     roll;
        int16_t     pitch;
        int16_t     yaw;
        int16_t     throttle;
        
        const uint8_t* ToArray();
        int GetSize();
        
        CTrimFlightBase& operator << ( const CTrimFlightBase& arg )
        {
            if( this !=  & arg )
            {
                roll = arg.roll;
                pitch = arg.pitch;
                yaw = arg.yaw;
                throttle = arg.throttle;
            }
            return *this;
        }
    private:
        int m_size;
    };
    
    class CTrimDriveBase
    {
    public:
        CTrimDriveBase();
        int16_t     wheel;
        
        const uint8_t* ToArray();
        int GetSize();
        CTrimDriveBase& operator << ( const CTrimDriveBase& arg )
        {
            if( this !=  & arg )
            {
                wheel = arg.wheel;
            }
            return *this;
        }
    private:
        int m_size;
    };
    
    class CTrimAll
    {
    public:
        CTrimAll();
        
        CTrimFlightBase    flight;
        CTrimDriveBase     drive;
        static CTrimAll* Parse(uint8_t* dataArray);
        int GetSize();
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
    private:
        int m_size;
    };
        
    class CTrimFlight : CTrimFlightBase
    {
    public:
        static CTrimFlight* Parse(uint8_t* dataArray);
    };
    
    class CTrimDrive : CTrimDriveBase
    {
    public:
        static CTrimDrive* Parse(uint8_t* dataArray);
    };
    
    class CFlightInfo
    {
    public:
        CFlightInfo();
        uint64_t    time;
        uint16_t    takeoff;
        uint16_t    landing;
        uint16_t    accident;
        
        CFlightInfo& operator << ( const CFlightInfo& arg )
        {
            if( this !=  & arg )
            {
                time = arg.time;
                takeoff = arg.takeoff;
                landing = arg.landing;
                accident = arg.accident;
            }
            return *this;
        }
        
        const uint8_t* ToArray();
        static CFlightInfo* Parse(uint8_t* dataArray);
        int GetSize();
    private:
        int m_size;
    };
    
    class CDriveInfo
    {
    public:
        CDriveInfo();
        uint64_t    time;
        uint16_t    accident;
        
        CDriveInfo& operator << ( const CDriveInfo& arg )
        {
            if( this !=  & arg )
            {
                time = arg.time;
                accident = arg.accident;
            }
            return *this;
        }
        
        const uint8_t* ToArray();
        static CDriveInfo* Parse(uint8_t* dataArray);
        int GetSize();
    private:
        int m_size;
    };
    
    
    class CIRMessage
    {
    public:
        CIRMessage();
        
        static CIRMessage* Parse(uint8_t* dataArray);
        const uint8_t* ToArray();
        const uint8_t* ToTransferDataBlock();
        const uint8_t* ToTransferDataBlockWifi();
        
        int GetSize();
        
        Direction::Enum direction;
        uint32_t irData;
    private:
        int m_size;
    };
}

#endif /* CommonClass_hpp */
