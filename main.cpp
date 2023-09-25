#include <cstdint>
#include <string>

#include <iostream>

#include <httplib.h>

typedef uint64_t IndexType;
typedef uint32_t SatelliteIDType;
typedef float FloatType;

using UTCTimeString = std::array<char, 20>; // DDMMYYYY:HHMMSS.SSSS

namespace Messages
{
    struct Message
    {
        virtual std::string name() const = 0;
        virtual size_t size() const = 0;
    };
    struct Position : Message
    {
        UTCTimeString time;    // At this time
        IndexType index;       // which box is the satellite in
        SatelliteIDType satid; // which satellite is it?
        FloatType position[3]; // The exact position
        FloatType velocity[3]; // the exact velocity

        virtual std::string name() const
        {
            return "Position";
        }

        virtual size_t size() const
        {
            return sizeof(Position);
        }
    };

    struct CDM : Message
    {
        UTCTimeString time; // At this time

        SatelliteIDType sat1_id;    // which satellite is it?
        FloatType sat1_position[3]; // The exact position
        FloatType sat1_velocity[3]; // the exact velocity

        SatelliteIDType sat2_id;    // which satellite is it?
        FloatType sat2_position[3]; // The exact position
        FloatType sat2_velocity[3]; // the exact velocity

        virtual std::string name() const
        {
            return "CDM";
        }

        virtual size_t size() const
        {
            return sizeof(CDM);
        }
    };

    struct TLE : Message
    {
        virtual std::string name() const
        {
            return "TLE";
        }

        virtual size_t size() const
        {
            return sizeof(TLE);
        }
    };
}

struct Client
{
    template <typename MessageType>
    void send(const MessageType &m)
    {
    }
};

struct Propagator : Client
{
};

struct Insertor : Client
{
};

struct Verifier : Client
{
};
int main()
{
    std::cerr << sizeof(Messages::Position) << std::endl;
    std::cerr << sizeof(Messages::CDM) << std::endl;

    Messages::Message *msg = new Messages::Position;
    std::cerr << msg->size() << " " << msg->name() << std::endl;

    return 0;
}