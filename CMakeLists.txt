cmake_minimum_required(VERSION 3.14)
project(BS)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-fexec-charset=CP949")

set(PROJECT_HEADERS BankingCommonDecl.h String.h Account.h NormalAccount.h HighCreditAccount.h  BankingSystem.h)
set(PROJECT_SOURCES main.cpp String.cpp Account.cpp NormalAccount.cpp HighCreditAccount.cpp  BankingSystem.cpp)

add_executable(BS ${PROJECT_SOURCES} ${PROJECT_HEADERS})