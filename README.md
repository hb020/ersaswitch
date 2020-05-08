# ersaswitch

This project is about an external switch to an Ersa i-CON controller.
It allows switching between tools, without voiding Ersa warranty (at least, nothing from Ersa is opened and no wires are cut), and without occupying more desk space.

Inspired by https://www.eevblog.com/forum/reviews/ersa-i-con2v-(port-switch-hack)/

But I have an i-con 1V.

The switch has 3 states: left, right and a timed inbetween "no tool". The latter is mandatory between left/right tools for about 2 secs for the controller to not freak out. The switch is fully isolated, and via monitoring of the signals, switches itself on and off automatically in sync with the controller.

There is stuff inside this git repo about implementing communication with the tools to show "too hot to touch" temperatures of the disconnected tool, but that was put on hold, as I wanted to try out the Attiny 214. That guy would probably be too small for a full comms stack and it would require some more components and a lot more time.

Does the switch work well? Yes, and it is a joy too, since the heat up time of the tools is so short. Really easy to use. One big pushbutton. I designed it so that the relay click pattern gives audible hints too, so in short time you don't even have to look anymore as for what tool is active. You just grab it.

Is it economically viable? Probably not for a one-off, as the BOM gets close to 100 EUR if you have to buy it all (meaning: case and so) in small qty locally from Europe or the US. Just get the i-con 2V if you really use more multiple tools regularly. But on the other hand you could use this to extend the port range of a 2V to 3 tools or more if you want (while keeping your warranty).

This should be easy to extend to 3 or more tools though. Just keep in mind that not all Ersa tools use only 5 wires. I have the i-tool and the Chip Tool Vario, and they only have 2 for power, 2 for logic, and 1 for earth. Some tools have more lines. If you have a tool with more lines, you'll have to change the relays.

