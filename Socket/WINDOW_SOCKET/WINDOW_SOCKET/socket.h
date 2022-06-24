#pragma once
#include <windows.h>
#include <iostream>
#include <winsock.h>
constexpr auto PORT = 6001;

using namespace std;

#pragma comment(lib,"ws2_32.lib")

#ifndef UNICODE
#define UNICODE 1
#endif

