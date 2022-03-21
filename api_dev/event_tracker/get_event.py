from time import sleep
import requests
import json

API_CLIENT_ID = "c930a6e8f8ffb6f3c041d58223158cfb00ab8e71b2783545b9f8046548d859c7"
API_SECRET_KEY = "1f619b3cc845649edd34be3365ba8ef9e4a645ca9c2c7f2c1959d4bbf1601d37"
authURL = "https://api.intra.42.fr/oauth/token"
authData = {'grant_type': 'client_credentials', 'client_id': API_CLIENT_ID, 'client_secret': API_SECRET_KEY}
r = requests.post(authURL, data = authData)
access_token = json.loads(r.text)['access_token']

print("ACCESS TOKEN : ")
print(access_token)



user_event_list = [] # event ids
def get_event():
    url = 'https://api.intra.42.fr/v2/campus/29/events/?access_token=' + access_token
    res = requests.get(url)
    data = json.load(res.text)
    print(data)
    # 현재 상위 이벤트 내용 리스트로 수집
    # register_event 를 통해서 이벤트 등록
    # register_event 에서는 유저의 이벤트 정보를 받아서 해당 내용이 중복되는지 확인함
    # 굳이 여러번 받지말고, 캐시해둔 리스트를 이용하도록하자.
    # cached list 에서 업데이트 된 경우에만 return true
    return (False)

def register_event(event_ids):
    # 인자로 전달된 event id에 대해서 register 진행
    for event in event_ids :
        url = 'https://api.intra.42.fr/v2/events_users' + event + '?access_token=' + access_token
        requests.post(url)
    pass

def do_program():
    while (True):
        event_id = get_event()
        if event_id:
            register_event(event_id)     
        sleep(3)

do_program()
