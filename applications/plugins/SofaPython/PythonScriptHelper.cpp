/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, development version     *
*                (c) 2006-2015 INRIA, USTL, UJF, CNRS, MGH                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                               SOFA :: Plugins                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/

#include "PythonScriptHelper.h"

namespace sofa {
namespace helper {

namespace internal {

PyObject* PythonScript_valueToPyObject(bool param)
{
    PyObject* value = nullptr;
    value = Py_BuildValue("b", param);
    return value;
}
PyObject* PythonScript_valueToPyObject(int param)
{
    PyObject* value = nullptr;
    value = Py_BuildValue("i", param);
    return value;
}
PyObject* PythonScript_valueToPyObject(unsigned int param)
{
    PyObject* value = nullptr;
    value = Py_BuildValue("UI", param);
    return value;
}
PyObject* PythonScript_valueToPyObject(double param)
{
    PyObject* value = nullptr;
    value = Py_BuildValue("d", param);
    return value;
}
PyObject* PythonScript_valueToPyObject(std::string const& param)
{
    PyObject* value = nullptr;
    value = Py_BuildValue("s", param.c_str());
    return value;
}

void PythonScript_pyObjectToValue(PyObject* pyObject, bool & val)
{
    if (!pyObject) return;
    if(PyBool_Check(pyObject))
        val = (Py_False != pyObject);
    else
        SP_MESSAGE_ERROR("Cannot convert pyObject to bool");
}

void PythonScript_pyObjectToValue(PyObject* pyObject, int & val)
{
    if (!pyObject) return;
    if(PyInt_Check(pyObject))
        val = (int)PyInt_AS_LONG(pyObject);
    else
        SP_MESSAGE_ERROR("Cannot convert pyObject to int");
}

void PythonScript_pyObjectToValue(PyObject* pyObject, float & val)
{
    if (!pyObject) return;
    if(PyFloat_Check(pyObject))
        val = (float)PyFloat_AS_DOUBLE(pyObject);
    else
        SP_MESSAGE_ERROR("Cannot convert pyObject to float");
}

void PythonScript_pyObjectToValue(PyObject* pyObject, double & val)
{
    if (!pyObject) return;
    if(PyFloat_Check(pyObject))
        val = PyFloat_AS_DOUBLE(pyObject);
    else
        SP_MESSAGE_ERROR("Cannot convert pyObject to double");
}
void PythonScript_pyObjectToValue(PyObject* pyObject, std::string & val)
{
    if (!pyObject) return;
    if(PyString_Check(pyObject))
        val = PyString_AS_STRING(pyObject);
    else
        SP_MESSAGE_ERROR("Cannot convert pyObject to std::string");
}

}  // namespase internal
}  // namespace helper
} // namespace sofa