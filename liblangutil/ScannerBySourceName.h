/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
// SPDX-License-Identifier: GPL-3.0
/**
 * Interface to retrieve the scanner by a source name.
 */

#pragma once

#include <string>

namespace solidity::langutil
{

class Scanner;

/**
 * Interface to retrieve a scanner from a source name.
 * Used especially for printing error information.
 */
class ScannerBySourceName
{
public:
	virtual ~ScannerBySourceName() = default;
	virtual langutil::Scanner const& scanner(std::string const& _sourceName) const = 0;
};

class ScannerBySourceNameForSingleScanner: public ScannerBySourceName
{
public:
	ScannerBySourceNameForSingleScanner(Scanner const& _scanner):
		m_scanner(_scanner) {}
	langutil::Scanner const& scanner(std::string const&) const override
	{
		return m_scanner;
	}
private:
	Scanner const& m_scanner;
};

}
