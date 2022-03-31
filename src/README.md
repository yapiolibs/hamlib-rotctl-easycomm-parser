# Easycomm parser for rotctl (work in progress)

References:
1. [examples](../test/test/)
2. [Hamlib/rotators/easycomm](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm)
3. [Hamlib protocol description (easycomm.txt)](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt)
4. [Hamlib protocol source (easycomm.c)](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt)

## Supported Commands

| Command    | Meaning                    | Perameters                                      | Hamlib Config Token | Standard | Supported |
|------------|----------------------------|-------------------------------------------------|---------------------|----------|-----------|
| Easycomm 1 | single line command        | AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD |                     | 1        | yes       |
| AZ         | azimuth                    | unsigned float, 1 decimal place [deg]           |                     | 2        | yes       |
| EL         | elevation                  | unsigned float, 1 decimal place [deg]           |                     | 2        | yes       |
| UP         | uplink freq                | in [Hz]                                         |                     | 2        | yes       |
| DN         | downlink freq              | in [Hz]                                         |                     | 2        | yes       |
| DM         | downlink Mode              | string,  [a-zA-Z]{1,3}, eg SSB, FM              |                     | 2        | yes       |
| UM         | uplink Mode                | string,  [a-zA-Z]{1,3}, eg SSB, FM              |                     | 2        | yes       |
| DR         | downlink Radio             | unsigned integer                                |                     | 2        | yes       |
| UR         | uplink Radio               | unsigned integer                                |                     | 2        | yes       |
| ML         | move Left                  |                                                 |                     | 2        | yes       |
| MR         | move Right                 |                                                 |                     | 2        | yes       |
| MU         | move Up                    |                                                 |                     | 2        | yes       |
| MD         | move Down                  |                                                 |                     | 2        | yes       |
| SA         | stop azimuth moving        |                                                 |                     | 2        | yes       |
| SE         | stop elevation moving      |                                                 |                     | 2        | yes       |
| AO         | AOS                        |                                                 |                     | 2        | yes       |
| LO         | LOS                        |                                                 |                     | 2        | yes       |
| OP         | set output                 | unsigned integer                                |                     | 2        | yes       |
| IP         | read an input              | unsigned integer                                |                     | 2        | yes       |
| AN         | read analogue input        | unsigned integer                                |                     | 2        | yes       |
| ST         | set time                   | YY:MM:DD:HH:MM:SS                               |                     | 2        | yes       |
| VE         | request Version            |                                                 |                     | 2        | yes       |
| VL         | velocity Left              | unsigned integer [mdeg/s]                       |                     | 3        | yes       |
| VR         | velocity Right             | unsigned integer [mdeg/s]                       |                     | 3        | yes       |
| VU         | velocity Up                | unsigned integer [mdeg/s]                       |                     | 3        | yes       |
| VD         | velocity Down              | unsigned integer [mdeg/s]                       |                     | 3        | yes       |
| CR         | read config                | register [0-x]                                  | 1                   | 3        | yes       |
| CW         | write config               | register [0-x]                                  | 2                   | 3        | yes       |
| GS         | get status register        |                                                 | 3                   | 3        | yes       |
| GE         | get error register         |                                                 | 4                   | 3        | yes       |
| VE         | request Version            |                                                 | 5                   | 3        | yes       |
| IP         | read an input number       |                                                 | 6                   | 3        | yes       |
| OP         | set output number          |                                                 | 7                   | 3        | yes       |
| AN         | read analogue input number |                                                 | 8                   | 3        | yes       |


| Status  | Meaning  |
|---------|----------|
| 1       | Idle     |
| 2       | Moving   |
| 4       | Pointing |
| 8       | Error    |

| Error  | Meaning      |
|--------|--------------|
| 1      | Sensor Error |
| 2      | Jam          |
| 4      | Homing Error |

| Register | Meaning   | Value  |
|----------|-----------|--------|
| 0        | MaxSpeed  | number |
| a        | Overshoot | 0/1/-  |
| b        | Jamming   | 0/1/-  |
| c        | Endpoints | 0/1/-  |
| d        | Unstick   | 0/1/-  |


## Supported Responses

| Response   | Meaning                    | Perameters                                      | Hamlib Config Token | Standard | Supported |
|------------|----------------------------|-------------------------------------------------|---------------------|----------|-----------|
| Easycomm 1 | single line command        | AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD |                     | 1        | no        |
|            |                            | AZaaa.a ELeee.e UPuuu UUU DNddd DDD             |                     |          | no        |
| AZ         | azimuth                    | unsigned float, 1 decimal place [deg]           |                     | 2        | no        |
| EL         | elevation                  | unsigned float, 1 decimal place [deg]           |                     | 2        | no        |
| UP         | uplink freq                | in [Hz]                                         |                     | 2        | no        |
| DN         | downlink freq              | in [Hz]                                         |                     | 2        | no        |
| DM         | downlink Mode              | string,  [a-zA-Z]{1,3}, eg SSB, FM              |                     | 2        | no        |
| UM         | uplink Mode                | string,  [a-zA-Z]{1,3}, eg SSB, FM              |                     | 2        | no        |
| DR         | downlink Radio             | unsigned integer                                |                     | 2        | no        |
| UR         | uplink Radio               | unsigned integer                                |                     | 2        | no        |
| AO         | AOS                        |                                                 |                     | 2        | no        |
| LO         | LOS                        |                                                 |                     | 2        | no        |
| IP         | read an input              | unsigned integer                                |                     | 2        | no        |
| AN         | read analogue input        | unsigned integer                                |                     | 2        | no        |
| VE         | request Version            |                                                 |                     | 2        | no        |
| VL         | velocity Left              | unsigned integer [mdeg/s]                       |                     | 3        | no        |
| VR         | velocity Right             | unsigned integer [mdeg/s]                       |                     | 3        | no        |
| VU         | velocity Up                | unsigned integer [mdeg/s]                       |                     | 3        | no        |
| VD         | velocity Down              | unsigned integer [mdeg/s]                       |                     | 3        | no        |
| CR         | read config                | register [0-x]                                  | 1                   | 3        | no        |
| GS         | get status register        |                                                 | 3                   | 3        | no        |
| GE         | get error register         |                                                 | 4                   | 3        | no        |


## Notes

* Commands are separated by ' ', or '\n' or '\cr'.
* In commands and responses:
  * integer number
    * has no fixed width
    * is not padded
  * float number
    * has no fixed width
    * is not padded
    * has one decimal digit