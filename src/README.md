# Easycomm parser for rotctl (work in progress)

[Hamlib/rotators/easycomm](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm)
([see easycomm.txt](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt))

| Command    | Meaning                    | Perameters                                      | Hamlib Config Token | Standard | Supported |
|------------|----------------------------|-------------------------------------------------|---------------------|----------|-----------|
| Easycomm 1 | single line command        | AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD |                     | 1        | yes       |
| ^^         | ^^                         | ^^ AZaaa.a ELeee.e UPuuu UUU DNddd DDD          |                     | ^^       |^^         |
| AZ         | azimuth                    | unsigned float, 1 decimal place [deg]           |                     | 2        | yes       |
| EL         | elevation                  | unsigned float, 1 decimal place [deg]           |                     | 2        | yes       |
| UP         | uplink freq                | in [Hz]                                         |                     | 2        | no        |
| DN         | downlink freq              | in [Hz]                                         |                     | 2        | no        |
| DM         | downlink Mode              | string,  [a-zA-Z]{1,3}, eg SSB, FM              |                     | 2        | no        |
| UM         | uplink Mode                | string,  [a-zA-Z]{1,3}, eg SSB, FM              |                     | 2        | no        |
| DR         | downlink Radio             | unsigned integer                                |                     | 2        | no        |
| UR         | uplink Radio               | unsigned integer                                |                     | 2        | no        |
| ML         | move Left                  |                                                 |                     | 2        | no        |
| MR         | move Right                 |                                                 |                     | 2        | no        |
| MU         | move Up                    |                                                 |                     | 2        | no        |
| MD         | move Down                  |                                                 |                     | 2        | no        |
| SA         | stop azimuth moving        |                                                 |                     | 2        | no        |
| SE         | stop elevation moving      |                                                 |                     | 2        | no        |
| AO         | AOS                        |                                                 |                     | 2        | no        |
| LO         | LOS                        |                                                 |                     | 2        | no        |
| OP         | set output                 | unsigned integer                                |                     | 2        | no        |
| IP         | read an input              | unsigned integer                                |                     | 2        | no        |
| AN         | read analogue input        | unsigned integer                                |                     | 2        | no        |
| ST         | set time                   | YY:MM:DD:HH:MM:SS                               |                     | 2        | no        |
| VE         | request Version            |                                                 |                     | 2        | no        |
| VL         | velocity Left              | unsigned integer [mdeg/s]                       |                     | 3        | no        |
| VR         | velocity Right             | unsigned integer [mdeg/s]                       |                     | 3        | no        |
| VU         | velocity Up                | unsigned integer [mdeg/s]                       |                     | 3        | no        |
| VD         | velocity Down              | unsigned integer [mdeg/s]                       |                     | 3        | no        |
| CR         | read config                | register [0-x]                                  | 1                   | 3        | no        |
| CW         | write config               | register [0-x]                                  | 2                   | 3        | no        |
| GS         | get status register        |                                                 | 3                   | 3        | no        |
| GE         | get error register         |                                                 | 4                   | 3        | no        |
| VE         | request Version            |                                                 | 5                   | 3        | no        |
| IP         | read an input number       |                                                 | 6                   | 3        | no        |
| OP         | set output number          |                                                 | 7                   | 3        | no        |
| AN         | read analogue input number |                                                 | 8                   | 3        | no        |


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
