# Wokwi-Chip-FrequencyCounter
## Description

Frequency Counter

-  0 - ?? Hz frequency range

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
"dependencies": { "chip-freq": "github:drf5n/Wokwi-Chip-FrequencyCounter@1.0.7" }
```

Then, add the chip to your circuit by adding a `chip-scope` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    {
      "type": "chip-freq",
      "id": "freq1",
      "attrs": { }
    },
```

The actual source code for the chip lives in [src/main.c](https://github.com/drf5na/Wokwi-Chip-FrequencyCounter/blob/main/src/main.c), and the pins are described in [chip.json](https://github.com/drf5na/Wokwi-Chip-FrequencyCounter/blob/main/chip.json).

## Examples

* [Wokwi Uno with Frequency Counter using this repository](https://wokwi.com/projects/406518140295703553) -- with counter and meter
* [Wokwi Uno with Frequency Counter using tabbed files](https://wokwi.com/projects/406335146945275905) -- with counter and meter
* [Wokwi Uno with Scope, PWM and Counter](https://wokwi.com/projects/390819301187622913)

### Wokwi files for monitor in a PWM pin:
```
void setup() {
  pinMode(3, OUTPUT);
  analogWrite(3, 128);
}

void loop() {
}

```

```
{
  "version": 1,
  "author": "drf5n",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-uno", "id": "uno", "top": 0, "left": 0, "attrs": {} },
    { "type": "chip-freq", "id": "freq1", "top": -75.78, "left": 273.6, "attrs": {} }
  ],
  "connections": [ [ "freq1:IN", "uno:3", "green", [ "h0" ] ] ],
  "dependencies": { "chip-freq": "github:drf5n/Wokwi-Chip-FrequencyCounter@1.0.8" }
}
```

## Versions
* github:drf5n/Wokwi-Chip-FrequencyCounter@1.0.7 -- Working release of Counter
* github:drf5n/Wokwi-Chip-FrequencyCounter@1.0.8 -- Add COUNT/!METER pin and frequency meter code for low frequency accuracy

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/drf5na/Wokwi-Chip-FrequencyCounter/blob/main/LICENSE) file for more details.
