#pragma once
//描述顶点缓冲区中每个顶点的数据布局，包括顶点的属性类型、数量和布局信息。
//通俗地说，它告诉程序如何解释顶点数据
//即给glVertexAttribPointer提供如何解析vbo的参数
#include <vector>

#include "glcall.h"

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
    static unsigned int GetSizeOfType(unsigned int type) {
        switch (type) {
        case GL_FLOAT: 			return 4;
        case GL_UNSIGNED_INT: 	return 4;
        case GL_UNSIGNED_BYTE: 	return 1;
        }
        ASSERT(false);
    }
};

class VertexBufferLayout {
public:
    VertexBufferLayout() : stride(0) {}

    inline const std::vector<VertexBufferElement> GetElements() const { return elements; }
    inline unsigned int GetStride() const { return stride; }
    template<typename T> void Push(unsigned int count) { ASSERT(false); }

private:
    std::vector<VertexBufferElement> elements;
    unsigned int stride;
};


template<>
inline void VertexBufferLayout::Push<float>(unsigned int count) {
    elements.push_back({ GL_FLOAT, count, GL_FALSE });
    stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

template<>
inline void VertexBufferLayout::Push<unsigned int>(unsigned int count) {
    elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
    stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template<>
inline void VertexBufferLayout::Push<unsigned char>(unsigned int count) {
    elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
    stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}

