# Easycomm parser for rotctl (work in progress)

[Hamlib/rotators/easycomm](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm)
([see easycomm.txt](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt))

| Command                                         | Meaning                     | Perameters                     | Hamlib Config Token  | Standard  | Supported  |
|-------------------------------------------------|-----------------------------|--------------------------------|----------------------|-----------|------------|
| AZaaa.a ELeee.e UPuuuuuuuuu UUU DNddddddddd DDD |                             |                                |                      | I         | yes        |
| AZ                                              | 	Azimuth                    | number - 1 decimal place [deg] |                      | II        | no         |
| EL	                                             | 	Elevation                  | number - 1 decimal place [deg] |                      | II        | no         |
| UP	                                             | 	Uplink freq                | in Hertz                       |                      | II        | no         |
| DN	                                             | 	Downlink freq              | in Hertz                       |                      | II        | no         |
| DM	                                             | 	Downlink Mode              | ascii, eg SSB, FM              |                      | II        | no         |
| UM	                                             | 	Uplink Mode                | ascii, eg SSB, FM              |                      | II        | no         |
| DR	                                             | 	Downlink Radio             | number                         |                      | II        | no         |
| UR	                                             | 	Uplink Radio               | number                         |                      | II        | no         |
| ML	                                             | 	Move Left                  |                                |                      | II        | no         |
| MR	                                             | 	Move Right                 |                                |                      | II        | no         |
| MU	                                             | 	Move Up                    |                                |                      | II        | no         |
| MD	                                             | 	Move Down                  |                                |                      | II        | no         |
| SA	                                             | 	Stop azimuth moving        |                                |                      | II        | no         |
| SE	                                             | 	Stop elevation moving      |                                |                      | II        | no         |
| AO	                                             | 	AOS                        |                                |                      | II        | no         |
| LO	                                             | 	LOS                        |                                |                      | II        | no         |
| OP	                                             | 	Set output                 | number                         |                      | II        | no         |
| IP	                                             | 	Read an input              | number                         |                      | II        | no         |
| AN	                                             | 	Read analogue input        | number                         |                      | II        | no         |
| ST	                                             | 	Set time                   | YY:MM:DD:HH:MM:SS              |                      | II        | no         |
| VE                                              | Request Version             |                                |                      | II        | no         |
| VL	                                             | 	Velocity Left              | number [mdeg/s]                |                      | III       | no         |
| VR	                                             | 	Velocity Right             | number [mdeg/s]                |                      | III       | no         |
| VU	                                             | 	Velocity Up	               | number [mdeg/s]                |                      | III       | no         |
| VD	                                             | 	Velocity Down              | number [mdeg/s]                |                      | III       | no         |
| CR	                                             | 	Read config                | register [0-x]	                | 1                    | III       | no         |
| CW	                                             | 	Write config               | register [0-x]	                | 2                    | III       | no         |
| GS	                                             | 	Get status register	       |                                | 3                    | III       | no         |
| GE	                                             | 	Get error register         |                                | 4                    | III       | no         |
| VE	                                             | 	Request Version            |                                | 5                    | III       | no         |
| IP	                                             | 	Read an input number       |                                | 6                    | III       | no         |
| OP	                                             | 	Set output number          |                                | 7                    | III       | no         |
| AN	                                             | 	Read analogue input number |                                | 8                    | III       | no         |


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
