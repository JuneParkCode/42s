from time import sleep
import requests
import json

API_CLIENT_ID = "c930a6e8f8ffb6f3c041d58223158cfb00ab8e71b2783545b9f8046548d859c7"
API_SECRET_KEY = "1f619b3cc845649edd34be3365ba8ef9e4a645ca9c2c7f2c1959d4bbf1601d37"
authURL = "https://api.intra.42.fr/oauth/token"
authData_cr = {'grant_type': 'client_credentials', 'client_id': API_CLIENT_ID, 'client_secret': API_SECRET_KEY}

r2 = requests.post(authURL, data = authData_cr)
access_token_cr = json.loads(r2.text)['access_token']

authData_auth = {
        'grant_type': 'authorization_code',
        'client_id': API_CLIENT_ID,
        'client_secret': API_SECRET_KEY,
        'redirect_uri' :'https://api.intra.42.fr/oauth/authorize?client_id=c930a6e8f8ffb6f3c041d58223158cfb00ab8e71b2783545b9f8046548d859c7&redirect_uri=https%3A%2F%2Fgithub.com%2FJuneParkCode&response_type=code',
        'headers' : {
            'Authorization': 'Bearer ' + access_token_cr
            } 
        }
r1 = requests.post(authURL, data = authData_auth):q
access_token_auth = json.loads(r1.text)['access_token']

user_event_list = [] # event ids

def get_me_info():
    url = 'https://api.intra.42.fr/v2/me?access_token=' + access_token_auth
    res = requests.get(url)
    print(res)
    data = json.loads(res.text)
    return (data)
def get_user_event():
    pass    

def get_event():
    url = 'https://api.intra.42.fr/v2/campus/29/events/?access_token=' + access_token_cr
    res = requests.get(url)
    data = json.loads(res.text)
    # 현재 상위 이벤트 내용 리스트로 수집
    # register_event 를 통해서 이벤트 등록
    # register_event 에서는 유저의 이벤트 정보를 받아서 해당 내용이 중복되는지 확인함
    # 굳이 여러번 받지말고, 캐시해둔 리스트를 이용하도록하자.
    # cached list 에서 업데이트 된 경우에만 return true
    return (False)

def register_event(event_ids):
    # 인자로 전달된 event id에 대해서 register 진행
    for event in event_ids :
        url = 'https://api.intra.42.fr/v2/events_users' + event + '?access_token=' + access_token_auth
        requests.post(url)
    pass

def do_program():
    get_me_info() 
    while (True):
        event_id = get_event()
        if event_id:
            register_event(event_id)     
        sleep(3)

#do_program()
def test():
    userInfo = get_me_info()
    print(userInfo)
    url ='https://api.intra.42.fr/v2/users/'+ 'id' +'/events_users?access_token=' + access_token_cr
    print(url)
    res = requests.get(url)
    print(res.text)
    data = json.loads(res.text)
    print(data)

test()
