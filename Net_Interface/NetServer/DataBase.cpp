#include<stddef.h>
 #include "DataBase.h"
#include"CException.h"
//#include<iostream>
//
//DataBase::DataBase()
//{
//	this->envHandle = NULL;
//	this->connHandle = NULL;
//	this->stmHandle = NULL;
//}
//
//void DataBase::DBConnection()
//{
//	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &envHandle))
//	{
//		SQLFreeHandle(SQL_HANDLE_STMT, stmHandle);
//		SQLDisconnect(connHandle);
//		SQLFreeHandle(SQL_HANDLE_DBC, connHandle);
//		SQLFreeHandle(SQL_HANDLE_ENV, envHandle);
//	}
//	if (SQL_SUCCESS != SQLSetEnvAttr(envHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
//	{
//		SQLFreeHandle(SQL_HANDLE_STMT, stmHandle);
//		SQLDisconnect(connHandle);
//		SQLFreeHandle(SQL_HANDLE_DBC, connHandle);
//		SQLFreeHandle(SQL_HANDLE_ENV, envHandle);
//	}
//	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, envHandle, &connHandle))
//	{
//		SQLFreeHandle(SQL_HANDLE_STMT, stmHandle);
//		SQLDisconnect(connHandle);
//		SQLFreeHandle(SQL_HANDLE_DBC, connHandle);
//		SQLFreeHandle(SQL_HANDLE_ENV, envHandle);
//	}
//
//	std::cout << "Attempting to connect to sql" << std::endl;
//
//	switch (SQLDriverConnect(connHandle,
//		NULL,
//		(SQLWCHAR*)L"DRIVER={SQL SERVER};SERVER=TUDOR-NB, 1434 ;DATABASE=NewsDB;uid=Tudor-NB\Tudor; Trusted=true;",
//		SQL_NTS,
//		conString,
//		1024,
//		NULL,
//		SQL_DRIVER_NOPROMPT))
//	{
//	case SQL_SUCCESS:
//		std::cout << "Conectare cu succes la sql server" << std::endl;
//		break;
//
//	case SQL_SUCCESS_WITH_INFO:
//		std::cout << "Conectare cu succes la sql server" << std::endl;
//		break;
//
//	case SQL_INVALID_HANDLE:
//		std::cout << "Conexiune esuata la sql server" << std::endl;
//		{
//			SQLFreeHandle(SQL_HANDLE_STMT, stmHandle);
//			SQLDisconnect(connHandle);
//			SQLFreeHandle(SQL_HANDLE_DBC, connHandle);
//			SQLFreeHandle(SQL_HANDLE_ENV, envHandle);
//		}
//
//	case SQL_ERROR:
//		std::cout << "Conexiune esuata la sql server" << std::endl;
//		{
//			SQLFreeHandle(SQL_HANDLE_STMT, stmHandle);
//			SQLDisconnect(connHandle);
//			SQLFreeHandle(SQL_HANDLE_DBC, connHandle);
//			SQLFreeHandle(SQL_HANDLE_ENV, envHandle);
//		}
//
//	default:
//		break;
//	}
//
//
//}

#include<iostream>
#include<string>
DataBase* DataBase::instance = nullptr;
DataBase::DataBase():state(-1)
{
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "Parola21@!", "NewsDB", 3306, NULL, 0);
	if (conn)
	{
		std::cout << "[DataBase]:Data Base Connected" << std::endl;
	}
	else
	{
		std::cout << "[DataBase]:Failed to connect to Data Base" << std::endl;
	}
}
DataBase* DataBase::get_instance()
{
	if (instance == nullptr)
		instance = new DataBase;
	return instance;
}

bool DataBase::Autentificare(std::string nume, std::string parola)//log in
{
    std::string query = "Select * from Useri where Nume = '" + nume + "' and Parola = '" + parola + "';";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn); //res retine rezultatul interogarii adica tot tabelul
        row = mysql_fetch_row(res); //row imparte tabelul pe randuri (row[0] = primul rand) functioneaza ca un vector
        while (row)
        {
            //printf("%s %s", row[0], row[1]);
            if (row[0] == nume && row[1] == parola)
                return true;
            row= mysql_fetch_row(res);
        }

   /*     if (row)
        {
            std::cout << "[DataBase]:s-a gasit userul" << std::endl;
            return true;
        }
        else
        {
            std::cout << "[DataBase]:nu s-a gasit userul" << std::endl;
            return false;
        }*/

    }
    return false;
}

bool DataBase::Inregistrare(std::string nume, std::string parola)//sign in 
{
    std::string query = "Select * from Useri where Nume = '" + nume + "' and Parola = '" + parola + "';";
    const char* q = query.c_str();
    state = mysql_query(conn, q);
    if (!state)
    {
     
        res = mysql_store_result(conn); //res retine rezultatul interogarii adica tot tabelul
        row = mysql_fetch_row(res); //row imparte tabelul pe randuri (row[0] = primul rand) functioneaza ca un vector
        while (row)
        {
            //printf("%s %s", row[0], row[1]);
            if (row[0] == nume && row[1] == parola)
                return false;
            row = mysql_fetch_row(res);
        }
        
        std::string insert_query = "insert into Useri values(\"" + nume + "\", \"" + parola + "\");";
        const char* ins_q = insert_query.c_str();
        state = mysql_query(conn, ins_q);
        if (!state)
        {
            res = mysql_store_result(conn);
            return true;
        }
        else
        {
            throw CException("A esuat Inregistrarea");
        }
    }
 
}

std::vector<CStire> DataBase::request_news(CStire::type_stire type)
{
    std::string query;
    if(type==CStire::type_stire::Economie)
         query = "Select * from News_list where Categorie = 'Economie';";
    else
        if (type == CStire::type_stire::Educatie)
            query = "Select * from News_list where Categorie = 'Educatie';";
        else
            if (type == CStire::type_stire::Medicina)
                query = "Select * from News_list where Categorie = 'Medicina';";
            else        
                if (type == CStire::type_stire::Relatii_internationale)
                 query = "Select * from News_list where Categorie = 'Relatii_Internationale';";
                else
                    if (type == CStire::type_stire::Sport)
                        query = "Select * from News_list where Categorie = 'Sport'; ";

    state = mysql_query(conn, query.c_str());

    std::vector<CStire> vec_news;
    if (!state)
    {
        res = mysql_store_result(conn); //res retine rezultatul interogarii adica tot tabelul
        row = mysql_fetch_row(res);
        while (row)
        {
            CStire elem(row[2], row[3], type,row[0]);
            vec_news.push_back(elem);
            row = mysql_fetch_row(res);
        }

    }
    else
    {
        std::cout << "eroare la executarea querilului\n";
    }

    return vec_news;
}
