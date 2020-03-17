#pragma once
#include <QtCore/QObject>
#include <QtWidgets/QLabel>
#include <iostream>
#include <nodes/DataModelRegistry>
#include <nodes/NodeDataModel>
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;
using QtNodes::NodeValidationState;
using QtNodes::PortIndex;
using QtNodes::PortType;
/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class ImageShowModel : public NodeDataModel
{
    Q_OBJECT
  public:
    ImageShowModel();
    virtual ~ImageShowModel()
    {
    }

  public:
    QString caption() const override
    {
        return QString("Image Display");
    }
    QString name() const override
    {
        return QString("ImageShowModel");
    }

  public:
    virtual QString modelName() const
    {
        return QString("Resulting Image");
    }
    unsigned int nPorts(PortType portType) const override;
    std::shared_ptr<NodeDataType> dataType(PortType portType, PortIndex portIndex) const override;
    std::shared_ptr<NodeData> outData(PortIndex port) override;
    void setInData(std::shared_ptr<NodeData> nodeData, PortIndex port) override;
    QWidget *embeddedWidget() override
    {
        return _label;
    }
    bool resizable() const override
    {
        return true;
    }
    std::unique_ptr<NodeDataModel> clone() const override
    {
        return std::make_unique<ImageShowModel>();
    }

  protected:
    bool eventFilter(QObject *object, QEvent *event) override;

  private:
    QLabel *_label;
    std::shared_ptr<NodeData> _nodeData;
};
