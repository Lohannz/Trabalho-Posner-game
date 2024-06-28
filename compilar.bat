@echo off
rem Script de compilação e execução do jogo em C

rem Compilação
gcc -o ./bin/Game.exe src\main.c src\combate.c src\item.c src\andamento.c -Iinclude -lm

rem Verifica se a compilação teve êxito
if %errorlevel% neq 0 (
    echo Compilação falhou. Verifique os erros acima.
    pause
    exit /b %errorlevel%
)

rem Execução do programa compilado
Game.exe

pause
