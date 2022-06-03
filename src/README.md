# Easycomm command reference

Table of supported commands as [described](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt) by Easycomm standard.
Note that the Easycomm standard is weakly described.
This table makes some assumptions in all conscience.
- :exclamation: ... not implemented
- :question: ... clarification needed

| Item     | Description                                     | Command/<br>Response  | Perameter                                                               | Structure                                                           | Example                                              | Easycomm<br>Standard | Hamlib<br>Config<br>Token |
|----------|-------------------------------------------------|-----------------------|-------------------------------------------------------------------------|---------------------------------------------------------------------|------------------------------------------------------|----------------------|---------------------------|
| *Std. 1* | set AZ/EL, <br>UP/DN frequency, <br>UP/DN-mode  | command               | AZ/EL: ufloat, 1 decimal<br>UP/DN: uint32<br>UUU/DDD: word, 1 to 3 char | `AZ\d{1,3}\.\d EL\d{1,3}\.\d UP\d{1,10} \S{1,3} DN\d{1,10} \S{1,3}` | `AZ123.1 EL123.1 UP1231231231 LSB DN1231231231 USB`  | 1                    |                           |
|          | post current AZ/EL, UP/DN frequency, UP/DN-mode | response              | same as *Standard 1* command                                            | same as *Easycomm 1* command                                        | same as *Easycomm 1* command                         | 1                    |                           |
| AZ       | get/set azimuth                                 | command               | ufloat, 1 decimal, [deg]                                                | `AZ(\d{1,3}\.\d)?`                                                  | set `AZ123.1`, get `AZ`                              | 2                    |                           |
|          | azimuth                                         | response              | same as AZ command                                                      | `AZ\d{1,3}\.\d`                                                     | `AZ123.1`                                            | 2                    |                           |
| EL       | set/get elevation                               | command               | ufloat, 1 decimal, [deg]                                                | `EL(\d{1,3}\.\d)?`                                                  | set `EL123.1`, get `EL`                              | 2                    |                           |
|          | elevation                                       | response              | same as EL command                                                      | `EL(\d{1,3}\.\d)`                                                   | `EL123.1`                                            | 2                    |                           |
| UP       | set/get uplink freq                             | command               | uint32, [Hz]                                                            | `UP(\d{1,10})?`                                                     | set `UP1231231231`, get `UR`                         | 2                    |                           |
|          | uplink freq                                     | response              | same as UP command                                                      | `UP(\d{1,10})`                                                      | `UP1231231231`                                       | 2                    |                           |
| DN       | set/get downlink freq                           | command               | uint32, [Hz]                                                            | `DN(\d{1,10})?`                                                     | set `DN1231231231`, get `DN`                         | 2                    |                           |
|          | downlink freq                                   | response              | same as DN command                                                      | `DN\d{1,10}`                                                        | `DN1231231231`                                       | 2                    |                           |
| DM       | set/get downlink mode                           | command               | word, 1 to 3 char                                                       | `DM(\S{1,3})?`                                                      | set `DMLSB`, `DMAM`, `DM-`; get `DM`                 | 2                    |                           |
|          | downlink mode                                   | response              | same as DM command                                                      | `DM\S{1,3}`                                                         | `DMLSB`                                              | 2                    |                           |
| UM       | set/get uplink mode                             | command               | word, 1 to 3 char                                                       | `UM(\S{1,3})?`                                                      | set `UMUSB`, `UMCW`, `UM-`; get `UM`                 | 2                    |                           |
|          | uplink mode                                     | response              | same as UM command                                                      | `UM\S{1,3}`                                                         | `UMUSB`                                              | 2                    |                           |
| DR       | set/get downlink radio                          | command               | uint8                                                                   | `DR(\d{1,3})?`                                                      | set `DR999`, get `DR`                                | 2                    |                           |
|          | downlink radio                                  | response              | same as DR command                                                      | `DR\d{1,3}`                                                         | `DR999`                                              | 2                    |                           |
| UR       | set/get uplink radio                            | command               | uint8                                                                   | `UR(\d{1,3})?`                                                      | set `UR999`, get `UR`                                | 2                    |                           |
|          | uplink radio                                    | response              | same as UR command                                                      | `UR\d{1,3}`                                                         | `UR999`                                              | 2                    |                           |
| ML       | move left until max or SA                       | command               | -                                                                       | `ML`                                                                | `ML`                                                 | 2                    |                           |
| MR       | move right until max or SA                      | command               | -                                                                       | `MR`                                                                | `MR`                                                 | 2                    |                           |
| MU       | move up until max or SE                         | command               | -                                                                       | `MU`                                                                | `MU`                                                 | 2                    |                           |
| MD       | move down until max or SE                       | command               | -                                                                       | `MD`                                                                | `MD`                                                 | 2                    |                           |
| SA       | stop azimuth moving                             | command               | -                                                                       | `SA`                                                                | `SA`                                                 | 2                    |                           |
| SE       | stop elevation moving                           | command               | -                                                                       | `SE`                                                                | `SE`                                                 | 2                    |                           |
| AO       | :question: AOS (acquisition of signal)          | command               | -:question:                                                             | `AO`:question:                                                      | :question:                                           | 2                    |                           |
|          | AOS                                             | :exclamation:response | :question:                                                              | :question:                                                          | :question:                                           | 2                    |                           |
| LO       | :question: LOS (loss of signal)                 | :question:command     | -:question:                                                             | `LO`:question:                                                      | :question:                                           | 2                    |                           |
|          | LOS                                             | :exclamation:response | :question:                                                              | :question:                                                          | :question:                                           | 2                    |                           |
| OP       | set output                                      | command               | uint16 number, bool value                                               | `OP\d{1,3},[01]`                                                    | `OP0,1`, `OP999,0`                                   | 2, 3                 |                           |
| IP       | read an input *Register*                        | command               | uint16 register                                                         | `IP\d{1,3}`                                                         | `IP0`, `IP1`, `IP2`, `IP3`, `IP999`                  | 2, 3                 |                           |
|          | read an input *Register*                        | response              | uint16 register, *Register* value                                       | `IP\d{1,3},[\S]+`                                                   | `IP0,0`, `IP1,1`, `IP2,1.141`, `IP3,-`, `IP999,asdf` | 2, 3                 |                           |
| AN       | read analogue input                             | command               | uint16 input                                                            | `AN\d{1,3}`                                                         | `AN0`, `AN999`                                       | 2, 3                 |                           |
|          | read analogue input                             | response              | uint16 input, uint16 value                                              | `AN\d{1,3},\d{1,5}`                                                 | `AN0,65535`, `AN999,0`                               | 2, 3                 |                           |
| ST       | set/get set time                                | command               | YY:MM:DD:HH:mm:SS                                                       | `ST(\d{2}:\d{2}:\d{2}:\d{2}:\d{2}:\d{2})?`                          | `ST22:01:19:02:30:16`                                | 2                    |                           |
| ST       | current time                                    | response              | YY:MM:DD:HH:mm:SS                                                       | `ST\d{2}:\d{2}:\d{2}:\d{2}:\d{2}:\d{2}`                             | `ST22:01:19:02:30:16`                                | 2                    |                           |
| VE       | request version                                 | command               | -                                                                       | `VE`                                                                | `VE`                                                 | 2, 3                 |                           |
|          | version                                         | response              | uint8 major, uint8t minor                                               | `VE\d{1,3}.\d{1,3}`                                                 | `VE0.123`                                            | 2                    |                           |
| VL       | set/get velocity left                           | command               | uint16, [mdeg/s]                                                        | `VL(\d{1,3})?`                                                      | set `VL123`, get `VL`                                | 3                    |                           |
|          | velocity Left                                   | response              | uint16, [mdeg/s]                                                        | `VL\d{1,3}`                                                         | `VL123`                                              | 3                    |                           |
| VR       | set/get velocity right                          | command               | uint16, [mdeg/s]                                                        | `VR(\d{1,3})?`                                                      | set `VR123`, get `VR`                                | 3                    |                           |
|          | velocity right                                  | response              | uint16, [mdeg/s]                                                        | `VR\d{1,3}`                                                         | `VR123`                                              | 3                    |                           |
| VU       | set/get velocity up                             | command               | uint16, [mdeg/s]                                                        | `VU(\d{1,3})?`                                                      | set `VU123`, get `VU`                                | 3                    |                           |
|          | velocity Up                                     | response              | uint16, [mdeg/s]                                                        | `VU\d{1,3}`                                                         | `VU123`                                              | 3                    |                           |
| VD       | set/get velocity down                           | command               | uint16, [mdeg/s]                                                        | `VD(\d{1,3})?`                                                      | set `VD123`, get `VD`                                | 3                    |                           |
|          | velocity down                                   | response              | uint16, [mdeg/s]                                                        | `VD\d{1,3}`                                                         | `VD123`                                              | 3                    |                           |
| CR       | read config register                            | command               | uint16 register                                                         | `CR\d{1,5}`                                                         | `CR1`                                                | 3                    | 1                         |
|          | config value                                    | response              | uint16 register, word, 1 to 28 char                                     | `CR\d{1,5},[\S]{1,28}`                                              | `CR1,0`, `CR1,123.1`, `CR2,adsf`                     | 3                    | 1                         |
| CW       | write config                                    | command               | uint16 register, word, 1 to 28 char                                     | `CW\d{1,5},[\S]{1,28}`                                              | `CW1,0`, `CW1,123.1`, `CW2,adsf`                     | 3                    | 2                         |
| GS       | get *Status* register                           | command               | -                                                                       | `GS`                                                                | `GS`                                                 | 3                    | 3                         |
|          | get *Status* register                           | response              | uint8 status flags                                                      | `GS\d{1,3}`                                                         | `GS1`, `GS9`                                         | 3                    | 3                         |
| GE       | get *Error* register                            | command               | -                                                                       | `GE`                                                                | `GE`                                                 | 3                    | 4                         |
|          | get *Error* register                            | response              | uint8 error flags                                                       | `GE\d{1,3}`                                                         | `GE1`, `GE5`                                         | 3                    | 4                         |


| *Status* | Meaning  |
|----------|----------|
| 1        | Idle     |
| 2        | Moving   |
| 4        | Pointing |
| 8        | Error    |

| *Error* | Meaning      |
|---------|--------------|
| 1       | Sensor Error |
| 2       | Jam          |
| 4       | Homing Error |

:question: Proposed mapping of configuration registers:

| *Register* | Meaning   | Value  |
|------------|-----------|--------|
| 0          | MaxSpeed  | number |
| a          | Overshoot | 0/1/-  |
| b          | Jamming   | 0/1/-  |
| c          | Endpoints | 0/1/-  |
| d          | Unstick   | 0/1/-  |

**Notes**
* Commands are separated by ' ' (space) or multiple spaces
* Lines are terminated by '\r', '\n' or '\r\n'
* In commands and responses:
  * integer number
    * has no fixed width
    * is not padded
  * float number
    * has no fixed width
    * is not padded
    * has one decimal digit
  * word
    * has no fixed length
    * contains no whitespace
  * strings
    * containing whitespaces are not supported

**References**
1. [Hamlib protocol description (easycomm.txt)](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.txt)
2. [Hamlib protocol source (easycomm.c)](https://github.com/Hamlib/Hamlib/tree/master/rotators/easycomm/easycomm.c)
3. [Unit tests](https://github.com/yapiolibs/hamlib-rotctl-easycomm-parser/tree/main/test/test)
4. Easycomm protocol
   1. `rotctl --list`
   2. `rotctl --model=204 --dump-caps`
