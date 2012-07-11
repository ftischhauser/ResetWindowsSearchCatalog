/*
	ResetWindowsSearchCatalog
	Copyright © 2012 Flavio Tischhauser <ftischhauser@gmail.com>
	https://github.com/ftischhauser/ResetWindowsSearchCatalog

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Windows.h>
#include <SearchAPI.h>

int main ( void )
{
	CoInitialize(NULL);
	ISearchManager *pSearchManager;
	if(SUCCEEDED(CoCreateInstance(CLSID_CSearchManager, NULL, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&pSearchManager))))
	{
		ISearchCatalogManager *pCatalogManager;
		if(SUCCEEDED(pSearchManager->GetCatalog(L"SystemIndex", &pCatalogManager)))
		{
			pCatalogManager->Reset();
			pCatalogManager->Release();
		}
		pSearchManager->Release();
	}
	return 0;
}
