#pragma once

#include <string>
#include <vector>
#include <Video/Graphics/Geometry/Vertex.hpp>

namespace drak {
template<typename T>
class Resource;
class MeshManager;
namespace geom {

class Mesh final {
	friend class Resource<Mesh>;
public:
	Mesh(const std::string& name, std::vector<Vertex1P1N1UV>&& vertices, std::vector<U32>&& indices);
	~Mesh() = default;

	using Manager = MeshManager;

	DK_GETTER_REF_C(std::string, name, m_name)
	DK_GETTER_REF_C(std::vector<Vertex1P1N1UV>, vertices, m_vertices)
	DK_GETTER_REF_C(std::vector<U32>, indices, m_indices)
private:
	Mesh() = default;

private:
	std::string					m_name;
	std::vector<Vertex1P1N1UV>	m_vertices;
	std::vector<U32>			m_indices;
};

} // namespace geom
} // namespace drak