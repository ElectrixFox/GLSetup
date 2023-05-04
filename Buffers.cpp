// Vertex buffer class
class VertexBuffer
{
private:
    GLuint m_RendererID;
public:
    VertexBuffer(const void* data, size_t size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;
};

VertexBuffer::VertexBuffer(const void* data, size_t size)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Index buffer class
class IndexBuffer
{
private:
    GLuint m_RendererID;
    GLuint m_Count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count; }
};

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : m_Count(count)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Frame buffer class
class FrameBuffer
{
private:
    GLuint m_RendererID;
public:
    FrameBuffer();
    ~FrameBuffer();

    void Bind() const;
    void Unbind() const;
};

FrameBuffer::FrameBuffer()
{
    glGenFramebuffers(1, &m_RendererID);
}

FrameBuffer::~FrameBuffer()
{
    glDeleteFramebuffers(1, &m_RendererID);
}

void FrameBuffer::Bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);
}

void FrameBuffer::Unbind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// Render buffer class
class RenderBuffer
{
private:
    GLuint m_RendererID;
public:
    RenderBuffer();
    ~RenderBuffer();

    void Bind() const;
    void Unbind() const;
};

RenderBuffer::RenderBuffer()
{
    glGenRenderbuffers(1, &m_RendererID);
}

RenderBuffer::~RenderBuffer()
{
    glDeleteRenderbuffers(1, &m_RendererID);
}

void RenderBuffer::Bind() const
{
    glBindRenderbuffer(GL_RENDERBUFFER, m_RendererID);
}

void RenderBuffer::Unbind() const
{
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

// Vertex array class
class VertexArray
{
private:
    GLuint m_RendererID;
public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;
    void AddVertexBuffer(const VertexBuffer& vb) const;
    void SetIndexBuffer(const IndexBuffer& ib) const;
};

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
}

