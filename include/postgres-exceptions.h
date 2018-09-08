/**
 * Copyright (c) 2016 Philippe FERDINAND
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/
#pragma once

#include <stdexcept>
#include <sstream>

namespace db {
  namespace postgres {
    
    /**
     * An exception that is raised when you try to read a value from a
     * query result using the wrong c++ type.
     */
    class TypeException : public std::exception {
    private:
      std::string expectedType;
      std::string message;

    public:
      const char * what() const throw () {
        return message.c_str();
      };

      TypeException(const std::string &pExpectedType): expectedType(pExpectedType) {
        message = "Unexpected C++ type. Please use as<" + expectedType
          + ">(int column)";
      }

      const std::string& GetExpectedType() const throw () {
        return expectedType;
      }
    };

    class UnsupportedTypeException : public std::exception {
    private:
      int unsupportedOid;
      std::string message;

    public:
      const char *what() const throw () {
        return message.c_str();
      }

      UnsupportedTypeException(int pUnsupportedOid): unsupportedOid(pUnsupportedOid) {
        std::stringstream s;
        s << "Unsupported PostgreSQL type with OID " << unsupportedOid;
        message += s.str();
      }

      int GetUnsupportedOID() {
        return unsupportedOid;
      }
    };

    /**
     * Exception thrown on connection failure.
     **/
    class ConnectionException : public std::runtime_error {
    public:
      /**
       * Constructor.
       *
       * @param what - The error message returned by the server.
       **/
      ConnectionException(const std::string &what)
      : std::runtime_error(what) {
      }
    };

    /**
     * Exception thrown on any runtime error except a connection failure.
     **/
    class ExecutionException : public std::runtime_error {
    public:
      /**
       * Constructor.
       *
       * @param what - The error message returned by the server.
       **/
      ExecutionException(const std::string &what)
      : std::runtime_error(what) {
      }
    };

  } // namespace postgres
}   // namespace db
