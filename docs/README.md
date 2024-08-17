# Wokwi Frequency Counter Chip Example

This is a basic custom chip for [Wokwi](https://wokwi.com/). It implements a simple inverter: the output is always opposite to the input.

## Pin names

| Name | Description               |
| ---- | ------------------------  |
| IN   | Input signal              |
| OUT  | Output (inverted) signal  |
| ENA  | Enable (ground to disable) |
| GND  | Ground                    |
| VCC  | Supply voltage            |

## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-freqCounter": "github:drf5n/Wokwi-freqCounter-chip@1.0.0"
  }
```

Then, add the chip to your circuit by adding a `chip-freqCounter` item to the `parts` section of diagram.json:

```json
  "parts": {
    ...,
    { "type": "chip-freqCounter", "id": "freqCounter1" }
  },
```

For a complete example, see [the freqCounter chip test project](https://wokwi.com/projects/406335146945275905).
