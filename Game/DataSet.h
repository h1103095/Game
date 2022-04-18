#pragma once

#include <odbcinst.h>
#include <sqlext.h>

#include "atldbcli.h"

#include "resource.h"
#include "DataSet.h"

typedef CCommand<CDynamicStringAccessorW, CRowset> DbCommand;

class CDataSet
{
public:
	CDataSet(void);
	~CDataSet(void);
	SQLHANDLE mh_environment;
	SQLHDBC mh_odbc;
	CSession m_dbSession;
	bool m_bOpenSession;
	bool Open(void);
	bool Query(CString strQuery, DbCommand* pDbCommand);
};

