/*
 MIT License
 
 Copyright (c) 2017 Elias Farhan
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <python/python_engine.h>

#include <pybind11/embed.h>// everything needed for embedding

#include "engine/scene.h"
#include "engine/game_object.h"
#include "engine/component.h"
#include <engine/utility.h>

namespace py = pybind11;

PYBIND11_MODULE(SFGE, m) 
{
	py::class_<Scene> scene(m, "Scene");
	py::class_<GameObject> game_object(m, "GameObject");
	py::class_<Component> component(m, "Component");

}

void init_python()
{
     // start the interpreter and keep it alive
    // use the Python API
}

void PythonManager::init()
{
	py::initialize_interpreter();
	py::print("Hello from Python!");
}

void PythonManager::update(sf::Time)
{
}

PythonManager::~PythonManager()
{
	py::finalize_interpreter();
}
