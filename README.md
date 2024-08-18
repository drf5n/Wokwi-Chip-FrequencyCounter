# Wokwi-Chip-FrequencyCounter
## Description

Frequency Counter

-  0 - ?? Hz frequency range

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
"dependencies": { "chip-freq": "github:drf5n/Wokwi-Chip-FrequencyCounter@1.0.6" }
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

* [Wokwi Uno using Github repository](https://wokwi.com/projects/406518140295703553)  https://github.com/drf6n/Wokwi-Chip-FrequencyCounter
* [Wokwi Uni using tabbed files](https://wokwi.com/projects/406335146945275905)

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
  "dependencies": { "chip-freq": "github:drf5n/Wokwi-Chip-FrequencyCounter@1.0.6" }
}
```

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/drf5na/Wokwi-Chip-FrequencyCounter/blob/main/LICENSE) file for more details.
