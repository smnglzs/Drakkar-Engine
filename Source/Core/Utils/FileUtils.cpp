#include <PrecompiledHeader/pch.hpp>
#include <Core/Utils/FileUtils.hpp>

namespace drak {
namespace io {

core::EError FileExists(const char* path) {
	if (!(_access_s(path, 0)))
		return DK_OK;
	else
		return core::EError::FILE_NOT_FOUND;

}

core::EError DirectoryExists(const char* path) {
	if (!(_access_s(path, 0)))
		return DK_OK;
	else
		return core::EError::DIRECTORY_NOT_FOUND;
}

core::EError CreateDirectory(const char* path) {
	if (!(_mkdir(path)))
		return DK_OK;
	else if (errno == EEXIST)
		return core::EError::DIRECTORY_ALREADY_EXIST;
	else
		return core::EError::DIRECTORY_NOT_CREATED;
}

DRAK_API core::EError CreateDirectories(const char* path) {
	core::EError err;
	std::string directory = path;
	size_t pos = 0, oldPos = 0;
	while((pos = directory.find_first_of('/')) != directory.npos ||
		(pos = directory.find_first_of('\\')) != directory.npos) {
		oldPos += pos + 1;
		directory = path;
		directory.erase(directory.begin() + oldPos, directory.end());
		if ((err = DirectoryExists(directory.c_str())) != DK_OK)
			if ((err = CreateDirectory(directory.c_str())) == core::EError::DIRECTORY_NOT_CREATED)
				return err;
		directory = path + oldPos;
	}
	return DK_OK;
}

core::EError CreateDirectoryIfDoesntExist(const char* path) {
	core::EError err;
	if ((err = DirectoryExists(path)) != DK_OK)
		return CreateDirectory(path);
	return core::EError::DIRECTORY_ALREADY_EXIST;
}

DRAK_API std::string Extension(const char* path) {
	std::string file(path);
	size_t pos = 0;
	if ((pos = file.find_last_of('.')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	return file;
}

DRAK_API std::string AllExtension(const char* path) {
	std::string file(path);
	size_t pos = 0;
	if ((pos = file.find_last_of('/')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_last_of('\\')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_first_of('.')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	return file;
}

DRAK_API std::string FileName(const char* path) {
	std::string file(path);
	size_t pos = 0;
	if ((pos = file.find_last_of('/')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_last_of('\\')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	return file;
}

DRAK_API std::string FileNameNoExtension(const char* path) {
	std::string file(path);
	size_t pos = 0;
	if((pos = file.find_last_of('/')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_last_of('\\')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_last_of('.')) != file.npos)
		file.erase(file.begin() + pos, file.end());
	return file;
}

DRAK_API std::string Directories(const char * path) {
	std::string file(path);
	size_t pos = 0;
	if ((pos = file.find_last_of('/')) != file.npos)
		file.erase(file.begin() + file.find_last_of('/') + 1, file.end());
	if ((pos = file.find_last_of('\\')) != file.npos)
		file.erase(file.begin() + file.find_last_of('\\') + 1, file.end());
	return file;
}

} // namespace io
} // namespace drak