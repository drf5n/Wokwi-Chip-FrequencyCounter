# Wokwi-Chip-freqCounter
## Description

Frequency Counter

-  0 - ?? Hz frequency range



To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
"dependencies": { "chip-freqCounter": "github:drf5n/Wokwi-Chip-freqCounter@1.0.0" }
```

Then, add the chip to your circuit by adding a `chip-scope` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    {
      "type": "chip-freqCounter",
      "id": "freqCounter1",
      "top": -37.38,
      "left": -61.6,
      "attrs": { }
    },
```

The actual source code for the chip lives in [src/main.c](https://github.com/drf5na/Wokwi-Chip-freqCounter/blob/main/src/main.c), and the pins are described in [chip.json](https://github.com/Dlloydev/Wokwi-Chip-PWM/blob/main/chip.json).

## Examples

[https://wokwi.com/projects/406335146945275905](https://wokwi.com/projects/406335146945275905) Test freqencyCounter chip.

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/drf5na/Wokwi-Chip-freqCounter/blob/main/LICENSE) file for more details.
