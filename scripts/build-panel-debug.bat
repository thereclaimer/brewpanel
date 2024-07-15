@echo off

pushd ..

@set bin_path= "bin\debug\panel"

if not exist %bin_path% (
    mkdir %bin_path%
)

@set cl_preprocessor= /D _UNICODE ^
                      /D UNICODE

@set cl_flags=        /Zi  ^
                      /MD  ^
                      /utf-8

@set cl_output=       /Fe:%bin_path%\Brewpanel.Panel.exe ^
                      /Fd:%bin_path%\Brewpanel.Panel.pdb ^
                      /Fo:%bin_path%\Brewpanel.Panel.obj

@set cl_includes=     /I src                ^
                      /I src\common         ^
                      /I src\win32          ^
                      /I vcpkg_installed\x64-windows\include

@set cl_src=          src\brewpanel.cpp

@set cl_link=         /link

@set cl_libs=         user32.lib

call cl.exe           ^
    %cl_preprocessor% ^
    %cl_flags%        ^
    %cl_output%       ^
    %cl_includes%     ^
    %cl_src%          ^
    %cl_link%         ^
    %cl_libs%


exit 0