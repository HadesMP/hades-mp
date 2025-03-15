local MessageIDs = {
    C2SCustomPayload = 0,
    S2CCustomPayload = 1
}


---
--- A message which represents arbitrary data from a Mod.
---
---@id 0
---@state play
---@class Net.C2S.CustomPayload
---@field Channel string The channel for the custom payload
---@field Content any The payload content
---


---
--- A message which represents arbitrary data from a Mod.
---
---@id 1
---@state play
---@class Net.S2C.CustomPayload
---@field Channel string The channel for the custom payload
---@field Content any The payload content
---
