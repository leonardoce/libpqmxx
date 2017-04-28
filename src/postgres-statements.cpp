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
#include "postgres-statements.h"

namespace db {
namespace postgres {

  // ---------------------------------------------------------------------------
  // Constructor
  // ---------------------------------------------------------------------------
  BatchStatement::BatchStatement(std::string sql)
  : sql_(std::move(sql)) {
  }
  
  // ---------------------------------------------------------------------------
  // Access to the sql string
  // ---------------------------------------------------------------------------
  BatchStatement::operator const char *() const {
    return sql_.c_str();
  }
  
  namespace literals {

    // ---------------------------------------------------------------------------
    // String literal to BatchStatement using the suffix _x
    // ---------------------------------------------------------------------------
    BatchStatement operator "" _x(const char *sql, size_t length) {
      return BatchStatement(std::string(sql, length));
    }
    
  }
  
} // namespace postgres
} // namespace db