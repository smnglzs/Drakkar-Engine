#include <Serialization/Serializer.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <Core/Utils/MacroUtils.hpp>
#include <fstream>

namespace drak {
namespace serialization {

template<EExtension ext, class T, bool addExtension>
core::EError Serializer::SerializeToFile(const T& t, const char* path, const char* filename) {
	core::EError err;
	if (DK_DIR_OK((err = drak::io::CreateDirectories(path)))) {
		if constexpr(ext == EExtension::INI) {
			if constexpr(addExtension)
				return SerializeToINI(t, path, (std::string(filename) + ".ini").c_str());
			else
				return SerializeToINI(t, path, filename);
		}
		else if constexpr (ext == EExtension::JSON) {
			if constexpr(addExtension)
				return SerializeToJSON(t, path, (std::string(filename) + ".json").c_str());
			else
				return SerializeToJSON(t, path, filename);
		}
		else if constexpr (ext == EExtension::BINARY) {
			if constexpr(addExtension)
				return SerializeToBinary(t, path, (std::string(filename) + ".bin").c_str());
			else
				return SerializeToBinary(t, path, filename);
		}
	}
	return err;
}

template<EExtension ext, class T, bool addExtension>
core::EError Serializer::SerializeToFile(const std::vector<T>& t, const char* path, const char* filename) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	core::EError err;
	if (DK_DIR_OK((err = drak::io::CreateDirectories(path)))) {
		if constexpr(ext == EExtension::INI) {
			if constexpr(addExtension)
				return SerializeToINI(t, path, (std::string(filename) + ".ini").c_str());
			else
				return SerializeToINI(t, path, filename);
		}
		else if constexpr (ext == EExtension::BINARY) {
			if constexpr(addExtension)
				return SerializeToBinary(t, path, (std::string(filename) + ".bin").c_str());
			else
				return SerializeToBinary(t, path, filename);
		}
	}
	return err;
}

template<EExtension ext, bool addExtension, class T, class ...VArgs>
core::EError Serializer::SerializeToFile(const char* path, const char* filename, const T& t, VArgs&& ...args) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	core::EError err;
	if (DK_DIR_OK((err = drak::io::CreateDirectories(path)))) {
		if constexpr(ext == EExtension::INI) {
			if constexpr(addExtension)
				return SerializeToINI(path, (std::string(filename) + ".ini").c_str(), t, std::forward<VArgs>(args)...);
			else
				return SerializeToINI(path, filename, t, std::forward<VArgs>(args)...);
		}
		else if constexpr (ext == EExtension::BINARY) {
			if constexpr(addExtension)
				return SerializeToBinary(path, (std::string(filename) + ".bin").c_str(), t, std::forward<VArgs>(args)...);
			else
				return SerializeToBinary(path, filename, t, std::forward<VArgs>(args)...);
		}
	}
	return err;
}

template<EExtension ext, class T, bool addExtension>
core::EError Serializer::AddObjectToFile(const T& t, const char* path) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	if constexpr(ext == EExtension::INI) {
		if constexpr(addExtension)
			return AddToINI(t, (std::string(path) + ".ini").c_str());
		else
			return AddToINI(t, path);
	}
	else if constexpr (ext == EExtension::BINARY) {
		if constexpr(addExtension)
			return AddToBinary(t, (std::string(path) + ".bin").c_str());
		else
			return AddToBinary(t, path);
	}
}

template<EExtension ext, class T, bool addExtension>
core::EError Serializer::AddObjectToFile(const std::vector<T>& t, const char* path) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	if constexpr(ext == EExtension::INI) {
		if constexpr(addExtension)
			return AddToINI(t, (std::string(path) + ".ini").c_str());
		else
			return AddToINI(t, path);
	}
	else if constexpr (ext == EExtension::BINARY) {
		if constexpr(addExtension)
			return AddToBinary(t, (std::string(path) + ".bin").c_str());
		else
			return AddToBinary(t, path);
	}
}

template<EExtension ext, bool addExtension, class T, class ...VArgs>
core::EError Serializer::AddObjectToFile(const char* path, const T& t, VArgs&& ...args) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	if constexpr(ext == EExtension::INI) {
		if constexpr(addExtension)
			return AddToINI((std::string(path) + ".ini").c_str(), t, std::forward<VArgs>(args)...);
		else
			return AddToINI(path, t, std::forward<VArgs>(args)...);
	}
	else if constexpr (ext == EExtension::BINARY) {
		if constexpr(addExtension)
			return AddToBinary((std::string(path) + ".bin").c_str(), t, std::forward<VArgs>(args)...);
		else
			return AddToBinary(path, t, std::forward<VArgs>(args)...);
	}
}

template<EExtension ext, class T, bool addExtension>
std::tuple<T, core::EError> Serializer::LoadFromFile(const char* path) {
	T t;
	return std::make_tuple(t, LoadFromFile<ext, T>(t, path));
}

template<EExtension ext, class T, bool addExtension>
core::EError Serializer::LoadFromFile(T& t, const char* path) {
	if constexpr(ext == EExtension::INI) {
		if constexpr(addExtension)
			return LoadFromINI(t, (std::string(path) + ".ini").c_str());
		else
			return LoadFromINI(t, path);
	}
	else if constexpr (ext == EExtension::JSON) {
		if constexpr(addExtension)
			return LoadFromJSON(t, (std::string(path) + ".json").c_str());
		else
			return LoadFromJSON(t, path);
	}
	else if constexpr (ext == EExtension::BINARY) {
		if constexpr(addExtension)
			return LoadFromBinary(t, (std::string(path) + ".bin").c_str());
		else
			return LoadFromBinary(t, path);
	}
}

template<EExtension ext, class T, bool addExtension>
core::EError Serializer::LoadEveryFromFile(std::vector<T>& t, const char* path) {
	static_assert(!(ext == EExtension::JSON), "Cannot load multiple object from JSON file !!");
	if constexpr(ext == EExtension::INI) {
		if constexpr(addExtension)
			return LoadFromINI(t, (std::string(path) + ".ini").c_str());
		else
			return LoadFromINI(t, path);
	}
	else if constexpr (ext == EExtension::BINARY) {
		if constexpr(addExtension)
			return LoadFromBinary(t, (std::string(path) + ".bin").c_str());
		else
			return LoadFromBinary(t, path);
	}
}

template<EExtension ext, class T, bool addExtension>
std::tuple<std::vector<T>, core::EError> Serializer::LoadEveryFromFile(const char* path) {
	std::vector<T> t;
	return std::make_tuple(t, LoadFromFile<ext, T>(t, path));
}

template<EExtension ext, bool addExtension, class T, class ...VArgs>
core::EError Serializer::LoadFromFile(const char* path, T& t, VArgs&& ...args) {
	static_assert(!(ext == EExtension::JSON), "Cannot load multiple object from JSON file !!");
	if constexpr(ext == EExtension::INI) {
		if constexpr(addExtension)
			return LoadFromINI<ext>((std::string(path) + ".ini").c_str(), t, std::forward<VArgs>(args)...);
		else
			return LoadFromINI<ext>(path, t, std::forward<VArgs>(args)...);
	}
	else if constexpr (ext == EExtension::BINARY) {
		if constexpr(addExtension)
			return LoadFromBinary<ext>((std::string(path) + ".bin").c_str(), t, std::forward<VArgs>(args)...);
		else
			return LoadFromBinary<ext>(path, t, std::forward<VArgs>(args)...);
	}
}

template<EExtension ext, class T, bool addExtension>
core::EError Serializer::Contain(const char* path, U32& count) {
	if constexpr(ext == EExtension::INI) {
		if constexpr(addExtension)
			return ContainINI((std::string(path) + ".ini").c_str(), count);
		else
			return ContainINI(path, count);
	}
	else if constexpr (ext == EExtension::JSON) {
		if constexpr(addExtension)
			return count = ContainJSON((std::string(path) + ".json").c_str());
		else
			return count = ContainJSON(path);
	}
	else if constexpr (ext == EExtension::BINARY) {
		if constexpr(addExtension)
			return ContainBinary((std::string(path) + ".bin").c_str(), count);
		else
			return ContainBinary(path, count);
	}
}


template<EExtension ext, class T, class ...VArgs>
void Serializer::SerializeToFile(std::fstream& file, std::stringstream& sstr,
	FileDescriptor& desc, const T& t, VArgs&& ...args) {
	int max = 0;
	for (auto& x : desc.m_descriptor) {
		if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName() && x.first.second > max)
			max = x.first.second;
	}
	if constexpr (types::IsVector_V<TYPEOF(t)>) {
		for (unsigned int i = 0; i < (unsigned int)t.size(); ++i) {
			desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName(), max + i }] = (int)sstr.tellp();
			MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::Serialize<ext>(t[i], sstr);
		}
	}
	else {
		desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), max }] = (int)sstr.tellp();
		MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Serialize<ext>(t, sstr);
	}
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		SerializeToFile<ext, VArgs...>(file, sstr, desc, std::forward<VArgs>(args)...);
}

template<EExtension ext, class T, class ...VArgs>
void Serializer::SerializeToFileNoDesc(std::fstream& file, std::stringstream& sstr, const T& t, VArgs&& ...args) {
	MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::Serialize<ext>(t, binary);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		SerializeToFileNoDesc<ext, VArgs...>(file, sstr, std::forward<VArgs>(args)...);
}

template<EExtension ext, class T, class ...VArgs>
void Serializer::LoadFromFile(std::stringstream& sstr, FileDescriptor& desc,
	std::map<std::string, int>& occurence, T& t, VArgs&& ...args) {
	if (desc.m_descriptor.find({ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(),
		occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName()] }) != desc.m_descriptor.end()) {
		if constexpr (types::IsVector_V<TYPEOF(t)>) {
			for (auto& x : desc.m_descriptor) {
				if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName())
					++occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName()];
			}
			if (occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName()]) {
				for (int i = 0, count = 
					occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName()];
					i < count; ++i) {

					sstr.seekg(desc.m_descriptor
						[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName(), i }],
						std::ios::beg);

					t.emplace_back();
					MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::Deserialize
						<ext>(t[t.size() - 1], sstr);
				}
			}
		}
		else {
			sstr.seekg(desc.m_descriptor
				[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName(),
				occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName()] }], std::ios::beg);
			MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::Deserialize<ext>(t, sstr);
			++occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(TYPEOF(t))>::TypeName()];
		}
	}
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		LoadFromFile<ext>(sstr, desc, occurence, std::forward<VArgs>(args)...);

}

template<class T, class ...VArgs>
void Serializer::Occurence(std::map<std::string, int>& occurence, const T& t, VArgs&& ...args) {
	occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName()] = 0;
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		Occurence(occurence, std::forward<VArgs>(args)...);
}

template<class T>
core::EError Serializer::SerializeToINI(const T& t, const char* path, const char* filename) {
	std::fstream file((std::string(path) + filename), std::ios::out);
	if (file.is_open()) {
		std::stringstream ini(std::ios::in | std::ios::out);
		MetaData<T>::Serialize<EExtension::INI>(t, ini);
		file << ini.rdbuf();
		file.flush();
		file.close();
		return DK_OK;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::SerializeToINI(const std::vector<T>& t, const char* path, const char* filename) {
	std::fstream file((std::string(path) + filename), std::ios::out);
	if (file.is_open()) {
		std::stringstream ini(std::ios::in | std::ios::out);
		for (int i = 0, size = (int)t.size(); i < size; ++i) 
			MetaData<T>::Serialize<EExtension::INI>(t[i], ini);
		file << ini.rdbuf();
		file.flush();
		file.close();
		return DK_OK;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T, class ...VArgs>
core::EError Serializer::SerializeToINI(const char* path, const char* filename, const T& t, VArgs&& ...args) {
	std::fstream file((std::string(path) + filename), std::ios::out);
	if (file.is_open()) {
		std::stringstream ini(std::ios::in | std::ios::out);
		SerializeToFileNoDesc<EExtension::INI>(file, ini, t, std::forward<VArgs>(args)...);
		file << ini.rdbuf();
		file.flush();
		file.close();
		return DK_OK;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::AddToINI(const T& t, const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path,  std::ios::app);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out);
			MetaData<T>::Serialize<EExtension::INI>(t, ini);
			file << ini.rdbuf();
			file.flush();
			file.close();
			return DK_OK;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
inline core::EError Serializer::AddToINI(const std::vector<T>& t, const char * path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::app);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out);
			for (auto& x : t)
				MetaData<T>::Serialize<EExtension::INI>(x, ini);
			file << ini.rdbuf();
			file.flush();
			file.close();
			return DK_OK;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T, class ...VArgs>
core::EError Serializer::AddToINI(const char* path, const T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::app);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out | std::ios::binary);
			SerializeToFileNoDesc<EExtension::INI>(file, ini, t, std::forward<VArgs>(args)...);
			file << ini.rdbuf();
			file.flush();
			file.close();
		}
		return DK_OK;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::LoadFromINI(T& t, const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out);
			ini << file.rdbuf();
			file.close();
			size_t it = ini.str().find((std::string("[") + MetaData<T>::TypeName()) + "]");
			if (it != std::string::npos) {
				ini.seekg(it, std::ios::beg);
				MetaData<T>::Deserialize<EExtension::INI>(t, ini);
				return DK_OK;
			}
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::LoadFromINI(std::vector<T>& t, const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out);
			ini << file.rdbuf();
			file.close();
			size_t it = ini.str().find((std::string("[") + MetaData<T>::TypeName()) + "]");
			if (it != std::string::npos) {
				while (it != std::string::npos) {
					ini.seekg(it, std::ios::beg);
					T t2;
					MetaData<T>::Deserialize<EExtension::INI>(t2, ini);
					t.emplace_back(t2);
					it = ini.str().find((std::string("[") + MetaData<T>::TypeName()) + "]");
				}
				return DK_OK;
			}
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<EExtension ext, class T, class ...VArgs>
core::EError Serializer::LoadFromINI(const char* path, T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in);
		if (file.is_open()) {
			FileDescriptor desc;
			std::map<std::string, int> occurence;
			Occurence(occurence, t, std::forward<VArgs>(args)...);
			file.seekg(0, std::ios::beg);
			std::stringstream ini(std::ios::in | std::ios::out);
			ini << file.rdbuf();
			file.close();
			std::string name;
			while (sscanf_s(ini.str(), "[%s]", name)) {
				desc[{ name, occurence[name] }] = (ini.str().find(name) - 1);
				++occurence[name];
				ini.seekg(desc[{ name, occurence[name] }] + 1);
			}
			Occurence(occurence, t, std::forward<VArgs>(args)...);
			ini.seekg(0, std::ios::beg);
			LoadFromFile<ext>(ini, desc, occurence, t, std::forward<VArgs>(args)...);
			return DK_OK;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::SerializeToJSON(const T& t, const char* path, const char* filename) {
	std::fstream file((std::string(path) + filename), std::ios::out);
	if (file.is_open()) {
		std::stringstream json(std::ios::in | std::ios::out);
		MetaData<T>::Serialize<EExtension::JSON>(t, json);
		file << json.rdbuf();
		file.flush();
		file.close();
		return DK_OK;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::LoadFromJSON(T& t, const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in);
		if (file.is_open()) {
			std::stringstream json(std::ios::in | std::ios::out);
			json << file.rdbuf();
			file.close();
			size_t it = json.str().find(std::string(MetaData<T>::TypeName()) + ":");
			if (it != std::string::npos) {
				json.seekg(it, std::ios::beg);
				MetaData<T>::Deserialize<EExtension::JSON>(t, json);
				return DK_OK;
			}
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::SerializeToBinary(const T& t, const char* path, const char* filename) {
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		desc.m_descriptor[{ MetaData<T>::TypeName(), 0 }] = 0;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		MetaData<T>::Serialize<EExtension::BINARY>(t, binary);
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return DK_OK;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::SerializeToBinary(const std::vector<T>& t, const char* path, const char* filename) {
	std::fstream file((std::string(path) + filename), std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		for (int i = 0, size = (int)t.size(); i < size; ++i) {
			desc.m_descriptor[{ MetaData<T>::TypeName(), i}] = (int)binary.tellp();
			MetaData<T>::Serialize<EExtension::BINARY>(t[i], binary);
		}
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return DK_OK;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T, class ...VArgs>
core::EError Serializer::SerializeToBinary(const char* path, const char* filename, const T& t, VArgs&& ...args) {
	std::fstream file((std::string(path) + filename), std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		SerializeToFile<EExtension::BINARY>(file, binary, desc, t, std::forward<VArgs>(args)...);
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return DK_OK;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::AddToBinary(const T& t, const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			int max = 0;
			for (auto& x : desc.m_descriptor) {
				if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName() && x.first.second > max)
					max = x.first.second;
			}
			desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), max + 1 }] = (int)binary.tellp();
			MetaData<T>::Serialize<EExtension::BINARY>(t, binary);
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
			return DK_OK;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::AddToBinary(const std::vector<T>& t, const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			for (auto& x : t) {
				int max = 0;
				for (auto& x2 : desc.m_descriptor) {
					if (x2.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName() && x2.first.second > max)
						max = x2.first.second;
				}
				desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), max + 1 }] = (int)binary.tellp();
				MetaData<T>::Serialize<EExtension::BINARY>(x, binary);
			}
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
			return DK_OK;
		}
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T, class ...VArgs>
core::EError Serializer::AddToBinary(const char* path, const T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			SerializeToFile<EExtension::BINARY>(file, binary, desc, t, std::forward<VArgs>(args)...);
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
		}
		return DK_OK;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::LoadFromBinary(T& t, const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			if (desc.m_descriptor.find({ MetaData<T>::TypeName(), 0 }) !=
				desc.m_descriptor.end()) {
				file.seekg(desc.m_descriptor
					[{ MetaData<T>::TypeName(), 0 }] + desc.m_endPos, std::ios::beg);
				std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
				binary << file.rdbuf();
				file.close();
				MetaData<T>::Deserialize<EExtension::BINARY>(t, binary);
				return DK_OK;
			}
			file.close();
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::LoadFromBinary(std::vector<T>& t, const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			int occurence = 0;
			for (auto& x : desc.m_descriptor) {
				if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName())
					++occurence;
			}
			if (occurence) {
				file.seekg(desc.m_descriptor
					[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 0 }] + desc.m_endPos, std::ios::beg);
				std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
				binary << file.rdbuf();
				file.close();
				for (int i = 0; i < occurence; ++i) {
					binary.seekg(desc.m_descriptor
						[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), i }], std::ios::beg);
					t.emplace_back();
					MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Deserialize
						<EExtension::BINARY>(t[t.size() - 1], binary);
				}
				return DK_OK;
			}
			file.close();
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<EExtension ext, class T, class ...VArgs>
core::EError Serializer::LoadFromBinary(const char* path, T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::map<std::string, int> occurence;
			Occurence(occurence, t, std::forward<VArgs>(args)...);
			file.seekg(desc.m_endPos, std::ios::beg);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			file.close();
			LoadFromFile<ext>(binary, desc, occurence, t, std::forward<VArgs>(args)...);
			return DK_OK;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<typename T>
core::EError Serializer::ContainBinary(const char* path, U32& count) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			file.close();
			count = 0;
			for (auto& x : desc.m_descriptor) {
				if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName())
					++occurence;
			}
			if (desc.find(MetaData<REMOVE_ALL_TYPE_MODIFIER<T>>::TypeName(), 0)) {
				return DK_OK;
			}
			else
				return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<typename T>
core::EError Serializer::ContainJSON(const char* path) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in);
		if (file.is_open()) {
			std::string str;
			getline(file, str);
			file.close();
			if (str == std::string(MetaData<REMOVE_ALL_TYPE_MODIFIER<T>>::TypeName()) + ": {") {
				return DK_OK;
			}
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<typename T>
core::EError Serializer::ContainINI(const char* path, U32& count) {
	if (drak::io::FileExists(path) == DK_OK) {
		std::fstream file(path, std::ios::in);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out);
			ini << file.rdbuf();
			file.close();
			size_t it = ini.str().find((std::string("[") + MetaData<T>::TypeName()) + "]");
			if (it != std::string::npos) {
				while (it != std::string::npos) {
					ini.seekg(it + 1, std::ios::beg);
					++count;
					it = ini.str().find((std::string("[") + MetaData<T>::TypeName()) + "]");
				}
				return DK_OK;
			}
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

} // namespace serialization
} // namespace drak
