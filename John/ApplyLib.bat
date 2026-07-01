mkdir "include"
mkdir "bin"

copy .\*.h ".\include"
cd .\include
del framework.h
del pch.h
mkdir "John"
move .\*.h ".\John"
cd ..

copy ..\x64\Debug\*.lib ".\bin"
copy ..\x64\Debug\*.dll ".\bin"
copy ".\include\John" "..\ExternalLibs\JohnBin\include\John"
copy ".\bin" "..\ExternalLibs\JohnBin\bin"

echo "Michael 67"