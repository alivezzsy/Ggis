#pragma once
//description: IBO (or EBO in OpenGL)
//处理索引缓冲对象
class IndexBuffer {
public:
	IndexBuffer(const unsigned int* data, unsigned int count, int mode);
	~IndexBuffer();
	void Bind() const;
	void Unbind() const;

	inline unsigned int getCount() const { return count; }
	inline int getMode() const { return mode; }
private:
	unsigned int rendererID;
	unsigned int count;
	int mode;
};

