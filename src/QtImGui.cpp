#include "QtImGui.h"
#include "ImGuiRenderer.h"
#include <QWindow>
#ifdef QT_WIDGETS_LIB
#include <QWidget>
#endif
#include <QScreen>

#include <QDebug>

namespace QtImGui {

class QWindowWrapper : public WindowWrapper
{
public:
  QWindowWrapper(ImGuiRenderer* r) :r(r) {}
  ~QWindowWrapper() {
    if (r && (r != ImGuiRenderer::instance())) {
      delete r;
    }
  }

public:
  void newFrame() { r->newFrame(); }

  void render() { r->render(); }
private:
  ImGuiRenderer* r;
};

#ifdef QT_WIDGETS_LIB

namespace {

class QWidgetWindowWrapper : public QWindowWrapper {
public:
    QWidgetWindowWrapper(QWidget *w, ImGuiRenderer* r) : w(w), QWindowWrapper(r) {}
    void installEventFilter(QObject *object) override {
        return w->installEventFilter(object);
    }
    QSize size() const override {
        return w->size();
    }
    qreal devicePixelRatio() const override {
        return w->devicePixelRatioF();
    }
    bool isActive() const override {
        return w->isActiveWindow();
    }
    QPoint mapFromGlobal(const QPoint &p) const override {
        return w->mapFromGlobal(p);
    }
    QObject* object() {
      return w;
    }
    void physicalDpi(float* ddpi, float* hdpi, float* vdpi)
    {
        *hdpi = w->physicalDpiX();
        *vdpi = w->physicalDpiY();
        *ddpi = std::max(*hdpi, *vdpi);
    }
private:
    QWidget *w;
};
}

RenderRef initialize(QWidget *window, bool defaultRender) {
  if (defaultRender) {
    auto* wrapper = new QWidgetWindowWrapper(window, ImGuiRenderer::instance());
    ImGuiRenderer::instance()->initialize(wrapper);
    return reinterpret_cast<RenderRef>(dynamic_cast<QWindowWrapper*>(wrapper));
  } else {
    auto* render = new ImGuiRenderer();
    auto* wrapper = new QWidgetWindowWrapper(window, render);
    render->initialize(wrapper);
    return reinterpret_cast<RenderRef>(dynamic_cast<QWindowWrapper*>(wrapper));
  }
}

#endif

namespace {

class QWindowWindowWrapper : public QWindowWrapper {
public:
    QWindowWindowWrapper(QWindow *w, ImGuiRenderer* r) : w(w), QWindowWrapper(r) {}
    void installEventFilter(QObject *object) override {
        return w->installEventFilter(object);
    }
    QSize size() const override {
        return w->size();
    }
    qreal devicePixelRatio() const override {
        return w->devicePixelRatio();
    }
    bool isActive() const override {
        return w->isActive();
    }
    QPoint mapFromGlobal(const QPoint &p) const override {
        return w->mapFromGlobal(p);
    }
    QObject* object() {
      return w;
    }
    void physicalDpi(float* ddpi, float* hdpi, float* vdpi)
    {
        *hdpi = w->screen()->physicalDotsPerInchX();
        *vdpi = w->screen()->physicalDotsPerInchY();
        *ddpi = std::max(*hdpi, *vdpi);
    }

private:
    QWindow *w;
};

}

RenderRef initialize(QWindow* window, bool defaultRender) {
  if (defaultRender) {
    auto* wrapper = new QWindowWindowWrapper(window, ImGuiRenderer::instance());
    ImGuiRenderer::instance()->initialize(wrapper);
    return reinterpret_cast<RenderRef>(dynamic_cast<QWindowWrapper*>(wrapper));
  }
  else {
    auto* render = new ImGuiRenderer();
    auto* wrapper = new QWindowWindowWrapper(window, render);
    render->initialize(wrapper);
    return reinterpret_cast<RenderRef>(dynamic_cast<QWindowWrapper*>(wrapper));
  }
}

void newFrame(RenderRef ref) {
  if (!ref) {
    ImGuiRenderer::instance()->newFrame();
  } else {
    auto wrapper = reinterpret_cast<QWindowWrapper*>(ref);
    wrapper->newFrame();
  }
}

void render(RenderRef ref)
{
  if (!ref) {
    ImGuiRenderer::instance()->render();
  } else {
    auto wrapper = reinterpret_cast<QWindowWrapper*>(ref);
    wrapper->render();
  }
}

double devicePixelRatio(RenderRef ref)
{
    if (!ref) {
      return ImGuiRenderer::instance()->devicePixelRatio();
    } else {
      auto wrapper = reinterpret_cast<QWindowWrapper*>(ref);
      return wrapper->devicePixelRatio();
    }
}

void physicalDpi(float* ddpi, float* hdpi, float* vdpi, RenderRef ref)
{
    if (!ref) {
      ImGuiRenderer::instance()->physicalDpi(ddpi, hdpi, vdpi);
    } else {
      auto wrapper = reinterpret_cast<QWindowWrapper*>(ref);
      wrapper->physicalDpi(ddpi, hdpi, vdpi);
    }
}

}
