# Delanger
There is a bug that causes some games to add keyboard layout to the system which oftenly can be removed only with reboot.

[People complain about Source-based games](https://steamcommunity.com/groups/SteamClientBeta/discussions/1/864976115478357063/)\
[ditto](https://itectec.com/superuser/how-to-prevent-source-engine-based-games-from-adding-the-english-us-keyboard-layout/)\
[ditto](https://answers.microsoft.com/en-us/windows/forum/all/keyboard-layout-changes-in-game/21d0ffec-55cc-46c5-aa4b-db99a222a263)\
[About Apex Legends too](https://answers.ea.com/t5/Bug-Reports/Adds-English-US-keyboard-to-Windows/td-p/7444127)\
...and many more

I was investigating the issue and found out that it happens with different games based on Source, but I cannot be sure if there is a bug in engine or somewhere else.
Since patching system or VAC-protected libraries is hardly an option, I decided to try to remove unwanted keyboard layouts through winapi and it totally worked, so I made it into a program.

## Usage
**delang.exe**\
Running the program without arguments makes it print a list of keyboard layouts and their codes, which can be used for next commands:

**delang.exe 0x4090409**\
or\
**delang.exe en-US**\
or\
**delang.exe en-US 1000**\
Running the program with argument makes it remove keyboard layout from system. It can be the layout code that must start with "0x" or locale name, which is case-sensitive. There is also an option to add second argument which will make the program wait after the start for mentioned amount of time in milliseconds.

It may be handy to create a shortcut to remove certain layout quickly or [make the program launch it together with a game](https://superuser.com/questions/745318/how-to-start-a-program-when-another-one-is-started) that causes an issue

## Disclaimer
Delanger is provided by Miles Seventh "as is" and "with all faults". Developer makes no representations or warranties of any kind concerning the safety, suitability, inaccuracies, typographical errors, or other harmful components of this software. You are solely responsible for the protection of your equipment and backup of your data, and the Developer will not be liable for any damages you may suffer in connection with using, modifying, or distributing this software.
