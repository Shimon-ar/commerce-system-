cmake_minimum_required(VERSION 3.15)
project(projectv3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projectv3
        Address.h
        Buyer.cpp
        Buyer.h
        BuyerSeller.h
        DynamicArray.h
        FeedBack.cpp
        FeedBack.h
        Item.cpp
        Item.h
        Items.cpp
        Items.h
        "known issues.txt"
        main.cpp
        Order.h
        Payment.cpp
        Payment.h
        Seller.cpp
        Seller.h
        StlArray.cpp
        system.cpp
        system.h
        User.cpp
        User.h)
