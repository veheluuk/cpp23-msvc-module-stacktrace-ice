# MSVC C++ modules are incompatible with `std::stacktrace`

## Bug description

Trying to use `std::stacktrace` in C++ module results in `fatal error C1001: Internal compiler error`.

Visual Studio: version 17.10.0 Preview 6.0

## How to reproduce

1. Clone this repository
2. Open repository folder as Visual Studio project
3. Build project
4. Build fails

## Error message

Version 17.10.0 Preview 6.0

```
------ Build All started: Project: cpp23-msvc-module-stacktrace, Configuration: x64-Debug ------
  [1/2] Building CXX object CMakeFiles\bug_repro.dir\main.cpp.obj
  FAILED: CMakeFiles/bug_repro.dir/main.cpp.obj 
  C:\PROGRA~1\MIB055~1\2022\Preview\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe  /nologo /TP   /DWIN32 /D_WINDOWS /EHsc /Ob0 /Od /RTC1 -std:c++latest -MDd -Zi /showIncludes @CMakeFiles\bug_repro.dir\main.cpp.obj.modmap /FoCMakeFiles\bug_repro.dir\main.cpp.obj /FdCMakeFiles\bug_repro.dir\ /FS -c D:\Development\cpp23-msvc-module-stacktrace\main.cpp
C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\include\stacktrace(183): fatal error C1001: Internal compiler error.
  (compiler file 'D:\a\_work\1\s\src\vctools\Compiler\CxxFE\sl\p1\c\convert.cpp', line 786)
   To work around this problem, try simplifying or changing the program near the locations listed above.
  If possible please provide a repro here: https://developercommunity.visualstudio.com 
  Please choose the Technical Support command on the Visual C++ 
   Help menu, or open the Technical Support help file for more information
  C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\include\stacktrace(183): note: the template instantiation context (the oldest one first) is
  D:\Development\cpp23-msvc-module-stacktrace\module_that_uses_stacktrace.ixx(5): note: see reference to class template instantiation 'std::basic_stacktrace<std::allocator<std::stacktrace_entry>>' being compiled
  ninja: build stopped: subcommand failed.

Build All failed.
```
