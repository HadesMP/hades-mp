---
--- Represents a client connected to the server.
---
---@class Net.Client
---
---

---
--- Subscribes to a message from a client
---
---@param ID int the message identifier
---@param Callback fun(Client: Net.Client, Message: any) the callback for the message
---
function SubscribeMessage(ID, Callback) end


---@param Message Net.S2C.CustomPayload
function SendCustomPayload(Client, Message) end