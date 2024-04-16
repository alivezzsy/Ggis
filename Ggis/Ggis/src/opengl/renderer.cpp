#include "renderer.h"
#include "glcall.h"

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
	GLCall(glClearColor(1.0f, 1.0f, 1.0f, 1.0f));
}

/* point */
void Renderer::DrawPoint(const VertexArray* vao, const IndexBuffer* ibo, Shader& pointShader)
{
	pointShader.Bind();
	vao->Bind();
	ibo->Bind();
	glPointSize(4);
	GLCall(glDrawElements(GL_POINTS, ibo->getCount(), GL_UNSIGNED_INT, nullptr));
	glPointSize(1);
}

/* line */
void Renderer::DrawLine(const VertexArray* vao, const IndexBuffer* ibo, Shader& lineShader)
{
	lineShader.Bind();
	vao->Bind();
	ibo->Bind();
	GLCall(glDrawElements(GL_LINE_STRIP, ibo->getCount(), GL_UNSIGNED_INT, nullptr));
}

/* polygon's interior zone */
void Renderer::DrawPolygon(const VertexArray* vao, const IndexBuffer* ibo, Shader& polygonShader)
{
	polygonShader.Bind();
	vao->Bind();
	ibo->Bind();

	// fill color
	GLCall(glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_INT, nullptr));
}


/* polygon's border */
void Renderer::DrawPolygonBorder(const VertexArray* vao, Shader& borderShader)
{
	borderShader.Bind();
	vao->Bind();

	int count = vao->getStridesCount();
	int offset = 0;
	for (int i = 0; i < count; ++i) {
		GLCall(glDrawArrays(GL_LINE_STRIP, offset, vao->getStride(i)));
		offset += vao->getStride(i);
	}
}

void Renderer::DrawHighlight(const VertexArray * vao, Shader & highlightShder)
{
	highlightShder.Bind();
	vao->Bind();

	int count = vao->getStridesCount();
	int offset = 0;
	for (int i = 0; i < count; ++i) {
		GLCall(glDrawArrays(GL_LINE_STRIP, offset, vao->getStride(i)));
		offset += vao->getStride(i);
	}
}


