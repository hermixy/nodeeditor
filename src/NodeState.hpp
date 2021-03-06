#pragma once

#include <memory>
#include <vector>

#include <QtCore/QUuid>

#include "PortType.hpp"

class NodeDataModel;

/// Contains vectors of connected input and output connections.
/// Stores bool for reacting on hovering connections
class NodeState
{
public:
  enum ReactToConnectionState
  {
    REACTING,
    NOT_REACTING
  };

public:

  NodeState(std::unique_ptr<NodeDataModel> const &model);

public:

  /// Returns vector of connections ID.
  /// Some of them can be empty (null)
  std::vector<QUuid> const& getEntries(PortType portType) const;

  /// Returns connection id for given endtype and
  /// given connection number
  QUuid const connectionID(PortType portType, size_t nEntry) const;

  /// Assign connection id to the given entry
  void setConnectionId(PortType portType, size_t nEntry, QUuid id);

  ReactToConnectionState reaction() const;

  void setReaction(ReactToConnectionState reaction);

  bool isReacting() const;

private:

  std::vector<QUuid> _sources;
  std::vector<QUuid> _sinks;

  ReactToConnectionState _reaction;
};
