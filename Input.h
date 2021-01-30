#pragma once

#include <thread>
#include <chrono>
#include <iostream>


class Input {
    public:
        Input() {
            S = true;
            thread = new std::thread( InputLoop , this );
            if( !thread ) {
                throw std::runtime_error("Failed To Create Input Thread");
            }
        }

        ~Input() {
            S = false;
            if( thread ) {
                thread->join();
                delete thread;
            }
        }
        
        Input(const Input& other) = delete;
        Input(const Input&& other) = delete;

        char GetInput() {
            return input;
        }
        void ClearInputs() {
            input = 0;
        }
        void Wait(int x) {
            std::this_thread::sleep_for(std::chrono::milliseconds(x));
        }

    private:

        static void InputLoop( Input* obj ) {

            while( obj->S ) {
                std::cin >> obj->input;
            }
        }

        std::thread* thread = nullptr;
        char input = 'w';
        bool S;
};