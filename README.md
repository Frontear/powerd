# powerd
A simple linux daemon that monitors ACPI events (AC, BAT) and adjusts kernel behaviour according to improve power savings (or performance). Unlike other power saving measures, powerd is dependency free and directly manipulates the kernel to provide the best power-saving features built-in. It is NOT recommended to use this alongside similar power-saving applications, as they will likely conflict and cause weird behaviour.

## License
This project is licensed under the [GNU GPL v3.0](https://github.com/Frontear/powerd/blob/main/LICENSE) license.
