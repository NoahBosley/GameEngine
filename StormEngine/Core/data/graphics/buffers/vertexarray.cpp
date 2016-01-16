#include "vertexarray.h"

namespace TheStormEngine { namespace buffer {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ArrayID);
	}

	VertexArray::~VertexArray()
	{
		for (GLuint i = 0; i < m_Buffers.size(); i++)
			delete m_Buffers[i];
	}

	void VertexArray::addBuffers(Buffer* buffer, GLuint index)
	{
		m_Buffers.push_back(buffer);

		bind();
		buffer->bind();
		
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		buffer->unbind();
		unbind();
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(m_ArrayID);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}

} }