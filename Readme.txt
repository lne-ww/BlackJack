To begin with, you need to download jsoncpp from Github.
Download link:
https://github.com/open-source-parsers/jsoncpp

Then, decompress the folder "include" and "src" to your project folder.

After that, change your project's attribute.
Add the path "include" to Attribute -> C/C++ -> Additional Include Directories.

Then, add ".../src/lib_json/json_tool.h" to your Header File and the other .cpp file in that folder to your Source File.

***PAY ATTENTION***
The "Plyaer" class has been rewritten by me in the Record.h/.cpp