#pragma once

#ifndef _FILES_H
#define _FILES_H

#include<iostream>
#include<sstream>
#include<fstream>
#include <direct.h>
using namespace std;

class FileLibrary {
public:
	FileLibrary(const string& _root_folder, string _file_extension = ".dat");

	~FileLibrary() {}
	
	template<typename type, typename TypeData>
	// Escribir en un archivo
	inline void log(type _file_name, int _data_quantity, const TypeData _data[]);

	template<typename type>
	// Obtener un dato de un archivo
	inline string get(const type _file_name, int _position);

	template<typename type>
	// Crear subcarpetas
	inline void createSubfolder(type _sub_folder);

	template<typename type>
	// Acceder a directorios
	inline FileLibrary& operator[](type _sub_folder);

private:
	template<typename type>
	// Armar la ruta de acceso
	inline void setDirectory(type _file_name);

	// Crear carpetas
	inline void createDirectory(string _folder);

private:
	ofstream file_write;
	ifstream file_read;
	string line, root_folder, file_path, sub_folder, file_extension;
	bool used_indexing;
};
#endif // !_FILES_H