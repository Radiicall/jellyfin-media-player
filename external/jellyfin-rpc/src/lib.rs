use std::ffi::{c_char, CStr};

use discord_rich_presence::DiscordIpcClient;
use jellyfin_rpc::prelude::*;
use CResult::{Ok, Err};

#[repr(C)]
pub struct Discord {
    client: discord_rich_presence::DiscordIpcClient
}

#[repr(C)]
pub enum CResult<T, E: Into<usize>> {
    Ok(T),
    Err(E),
}

impl Discord {
    #[no_mangle]
    pub extern "C" fn new(client_id: *const c_char) -> CResult<Self, usize> {
        if client_id.is_null() {
            return Err(0);
        }
        let client_id_cstr = unsafe {CStr::from_ptr(client_id)};

        let client_id = match client_id_cstr.to_str() {
            Result::Ok(client_id) => client_id,
            Result::Err(_) => return Err(0),
        };

        let client: DiscordIpcClient = match discord_rich_presence::DiscordIpcClient::new(client_id) {
            Result::Ok(client) => client,
            Result::Err(_) => return Err(0),
        };

        Ok(Self {
            client,
        })
    }
}

#[no_mangle]
pub extern "C" fn add(left: usize, right: usize) -> usize {
    left + right
}

#[no_mangle]
pub extern "C" fn connect(discord: &mut Discord) {
    jellyfin_rpc::connect(&mut discord.client)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
